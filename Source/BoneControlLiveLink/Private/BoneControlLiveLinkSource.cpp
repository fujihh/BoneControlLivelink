// Fill out your copyright notice in the Description page of Project Settings.


#include "BoneControlLiveLinkSource.h"

#include "ILiveLinkClient.h"
#include "LiveLinkTypes.h"
#include "Roles/LiveLinkAnimationRole.h"
#include "Roles/LiveLinkAnimationTypes.h"

#include "Common/UdpSocketBuilder.h"
#include "SocketSubsystem.h"
#include "HAL/RunnableThread.h"
#include "Async/Async.h"
#include "Sockets.h"

#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Kismet/KismetMathLibrary.h"
#include "FParseJson.h"
//#include "Math/UnrealMathUtility.h"


#define LOCTEXT_NAMESPACE "BoneControlLiveLinkSource"
#define RECV_BUFFER_SIZE 1024 *1024 //»º³åÇø

FBoneControlLiveLinkSource::FBoneControlLiveLinkSource(FIPv4Endpoint Endpoint)
	:Socket(nullptr)
	, Stopping(false)
	, Thread(nullptr)
	, WaitTime(FTimespan::FromMilliseconds(100))

{
	LastFrameBonesRotation.Init(FRotator(0, 0, 0), 1);//test only upperarm_l 
	DeviceEndpoint = Endpoint;
	SourceStatus = LOCTEXT("SourceStatus_DeviceNotFound", "Device Not Found");
	SourceType = LOCTEXT("BoneControlLiveLinkSourceType", "BoneControl LiveLink");
	SourceMachineName = LOCTEXT("BoneControlLiveLinkSourceMachineName", "localhost");
	SubjectName = TEXT("BoneControlLiveLink Subject");

	if (DeviceEndpoint.Address.IsMulticastAddress()) { //Checks whether this IP address is a multicast address. 
		//it's unworked Currently 
	}
	else {
		//set Socket
		//FUdpSocketBuilder tempSocket(TEXT("MYSOCKET"));
		Socket = FUdpSocketBuilder(TEXT("MYSOCKET"))
			.AsNonBlocking()//Set Socket operations to be non-blocking 
			.AsReusable()//Makes the bound address reusable by other sockets
			.BoundToAddress(DeviceEndpoint.Address)
			.BoundToPort(DeviceEndpoint.Port)
			.WithReceiveBufferSize(RECV_BUFFER_SIZE);
	}
	RecvBuffer.SetNumUninitialized(RECV_BUFFER_SIZE);//ReSize Array bound  here is 2^20

	if ((Socket != nullptr) && (Socket->GetSocketType() == SOCKTYPE_Datagram)) {  //here we choose UDP socket ;  TCP type socket: SOCKTYPE_Streaming
		Start();
		SourceStatus = LOCTEXT("SourceStatus_Receiving", "Receiving");
	}

}
FBoneControlLiveLinkSource::~FBoneControlLiveLinkSource() {
	Stop();
	if (Thread != nullptr) {
		Thread->WaitForCompletion();
		delete Thread;
		Thread = nullptr;
	}
	if (Socket != nullptr) {
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}
}

void FBoneControlLiveLinkSource::ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid) {
	Client = InClient;
	SourceGuid = InSourceGuid;
}

bool FBoneControlLiveLinkSource::IsSourceStillValid() const {
	bool bIsSourceValid = !Stopping && Thread != nullptr;
	return bIsSourceValid;
}

bool FBoneControlLiveLinkSource::RequestSourceShutdown() {
	Stop();
	SourceStatus = LOCTEXT("SourceStatus_Stopped", "stopped");
	return true;
}

void FBoneControlLiveLinkSource::Start() {
	ThreadName = "My UDP Recevier:";
	ThreadName.AppendInt(FAsyncThreadIndex::GetNext());
	Thread = FRunnableThread::Create(this, *ThreadName, 128 * 1024, TPri_AboveNormal, FPlatformAffinity::GetPoolThreadMask());
}

void FBoneControlLiveLinkSource::Stop() {
	Stopping = true;
}

uint32 FBoneControlLiveLinkSource::Run() {

	uint32 temp = 0;
	if (Socket != nullptr) {

		//UE_LOG(LogTemp, Warning, TEXT("BoneControlLiveLink_RUN_Test"));
		while (!Stopping) {
			if (Socket->Wait(ESocketWaitConditions::WaitForRead, WaitTime)) {
				auto addr_in = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
				int32 bytes_read = 0;
				RecvBuffer.GetData();
				if (Socket->RecvFrom(RecvBuffer.GetData(), RecvBuffer.Num(), bytes_read, *addr_in) && bytes_read > 0) {

					if (Stopping) { break; }
					TSharedPtr<TArray<uint8>, ESPMode::ThreadSafe> ReceivedData = MakeShareable(new TArray<uint8>());
					ReceivedData->SetNumUninitialized(bytes_read);
					memcpy(ReceivedData->GetData(), RecvBuffer.GetData(), bytes_read);
					HandleReceivedData(ReceivedData);
					//AsyncTask(ENamedThreads::GameThread, [this, ReceivedData]() { HandleReceivedData(ReceivedData); });
				}
			}
		}
		Socket->Close();

	}
	return 0;
}

void FBoneControlLiveLinkSource::HandleReceivedData(TSharedPtr<TArray<uint8>, ESPMode::ThreadSafe> ReceivedData) {

	FString JsonString;
	bool isRotation = true;
	JsonString.Empty(ReceivedData->Num());
	for (uint8& Byte : *ReceivedData.Get())
	{
		JsonString += TCHAR(Byte);
	}


	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject)) {
		//TSharedPtr<FJsonObject> CurrentFrameInfo = JsonObject->GetObjectField("Frame");
		//TSharedPtr<FJsonObject> CurrentFrameBones = JsonObject->GetObjectField("Bones");
		
		int BoneIndex = 0;
		bool bCreateSubject = !EncounteredSubjects.Contains(SubjectName);
		if (bCreateSubject)
		{
			FBoneControlLiveLinkSource::HandleSuitData();

			FLiveLinkFrameDataStruct FrameDataStruct = FLiveLinkFrameDataStruct(FLiveLinkAnimationFrameData::StaticStruct());
			FLiveLinkAnimationFrameData& FrameData = *FrameDataStruct.Cast<FLiveLinkAnimationFrameData>();
			
			FParseJson DataJson(JsonObject);
			DataJson.ParseBone();
			DataJson.getBonesTransform();
			
			FrameData.Transforms.SetNumUninitialized(DataJson.getBonesTransform().Num());

			//for (TPair<FString, TSharedPtr<FJsonValue>>& Bone : CurrentFrameBones->Values) {
			//	TSharedPtr<FJsonObject> SingalBoneObject = Bone.Value->AsObject();
			//	FString BoneName = Bone.Key;
			//	FVector BoneLocation;
			//	//FQuat BoneRotation;
			//	FRotator BoneRotation;
			//	FQuat BoneQuat;
			//	FRotator LastBoenRotation;
			//	const TArray<TSharedPtr<FJsonValue>>* RotationArray;
			//	const TArray<TSharedPtr<FJsonValue>>* LocationArray;
			//	LastBoenRotation = FRotator(FrameData.Transforms[BoneIndex].GetRotation());

			//	if (SingalBoneObject->TryGetArrayField(TEXT("Rotation"), RotationArray) ) {
			//		if (RotationArray->Num() == 3) {
			//			double X = (*RotationArray)[0]->AsNumber();
			//			double Y = (*RotationArray)[1]->AsNumber();
			//			double Z = (*RotationArray)[2]->AsNumber();
			//			BoneRotation = FRotator(X, Y, Z);
			//		}
			//		else if (RotationArray->Num() == 4) {

			//			double X = (*RotationArray)[0]->AsNumber();
			//			double Y = (*RotationArray)[1]->AsNumber();
			//			double Z = (*RotationArray)[2]->AsNumber();
			//			double W = (*RotationArray)[3]->AsNumber();
			//			BoneQuat = FQuat(X, Y, Z, W);
			//			isRotation = false;
			//		}
			//	}
			//	if (SingalBoneObject->TryGetArrayField(TEXT("Position"), LocationArray)) {
			//		double X = (*LocationArray)[0]->AsNumber();
			//		double Y = (*LocationArray)[1]->AsNumber();
			//		double Z = (*LocationArray)[2]->AsNumber();
			//		BoneLocation = FVector(X, Y, Z);
			//	}
			//	FVector BoneScale(1, 1, 1);
			//
			//	FrameData.Transforms[BoneIndex] = FTransform((RotationArray->Num()==3?FQuat(BoneRotation):BoneQuat), BoneLocation, BoneScale);


			//	LastFrameBonesRotation[0] = BoneRotation;
			//	BoneIndex++;

			//}
			Client->PushSubjectFrameData_AnyThread({ SourceGuid, SubjectName }, MoveTemp(FrameDataStruct));
		}

	}
	return;
}




void FBoneControlLiveLinkSource::HandleSuitData()
{

	/*suitNames.Add(suit.GetSubjectName());*/

	FLiveLinkSubjectKey Key = FLiveLinkSubjectKey(SourceGuid, SubjectName);

	TArray<FName> boneNames;
	boneNames.Add("root");
	boneNames.Add("pelvis");
	boneNames.Add("spine_01");
	boneNames.Add("spine_03");
	boneNames.Add("spine_05");
	boneNames.Add("neck_01");
	boneNames.Add("head");

	boneNames.Add("clavicle_l");
	boneNames.Add("upperarm_l");
	boneNames.Add("lowerarm_l");
	boneNames.Add("hand_l");

	boneNames.Add("clavicle_r");
	boneNames.Add("upperarm_r");
	boneNames.Add("lowerarm_r");
	boneNames.Add("hand_r");

	boneNames.Add("thigh_r");
	boneNames.Add("calf_r");
	boneNames.Add("foot_r");
	boneNames.Add("ball_r");

	boneNames.Add("thigh_l");
	boneNames.Add("calf_l");
	boneNames.Add("foot_l");
	boneNames.Add("ball_l");





	TArray<int32> boneParents;
	boneParents.Add(0); //0 - root
	boneParents.Add(0); //1 - pelvis
	boneParents.Add(1); //2 - spine_01
	boneParents.Add(2); //3 - spine_03
	boneParents.Add(3); //4 - spine_05
	boneParents.Add(4); //5 - neck
	boneParents.Add(5); //6 - head
	boneParents.Add(4); //7 - clavicle_l
	boneParents.Add(7); //8 - upperarm_l
	boneParents.Add(8); //9 - lowerarm_l
	boneParents.Add(9); //10 - hand_l
	boneParents.Add(4); //11 - clavicle_r
	boneParents.Add(11); //12 - upperarm_r
	boneParents.Add(12); //13 - lowerarm_r
	boneParents.Add(13); //14 - hand_r
	boneParents.Add(1); //15 - thigh_r
	boneParents.Add(15); //16 - calf_r
	boneParents.Add(16); //17 - foot_r
	boneParents.Add(17); //18 - ball_r
	boneParents.Add(1); //19 - thigh_l
	boneParents.Add(19); //20 - calf_l
	boneParents.Add(20); //21 - foot_l
	boneParents.Add(21); //22 - ball_l

	//boneParents.Add(0); //0 - root
	//boneParents.Add(0); //1 - pelvis
	//boneParents.Add(0); //2 - spine_01
	//boneParents.Add(2); //3 - spine_03
	//boneParents.Add(0); //4 - spine_05
	//boneParents.Add(2); //5 - neck
	//boneParents.Add(3); //6 - head
	//boneParents.Add(1); //7 - clavicle_l
	//boneParents.Add(4); //8 - upperarm_l
	//boneParents.Add(5); //9 - lowerarm_l
	//boneParents.Add(6); //10 - hand_l
	//boneParents.Add(1); //11 - clavicle_r
	//boneParents.Add(8); //12 - upperarm_r
	//boneParents.Add(9); //13 - lowerarm_r
	//boneParents.Add(10); //14 - hand_r
	//boneParents.Add(0); //15 - thigh_r
	//boneParents.Add(12); //16 - calf_r
	//boneParents.Add(13); //17 - foot_r
	//boneParents.Add(14); //18 - ball_r
	//boneParents.Add(0); //19 - thigh_l
	//boneParents.Add(16); //20 - calf_l
	//boneParents.Add(17); //21 - foot_l
	//boneParents.Add(18); //22 - ball_l

	FLiveLinkStaticDataStruct StaticData(FLiveLinkSkeletonStaticData::StaticStruct());
	FLiveLinkSkeletonStaticData* SkeletonData = StaticData.Cast<FLiveLinkSkeletonStaticData>();
	SkeletonData->SetBoneNames(boneNames);
	SkeletonData->SetBoneParents(boneParents);


	if (Client)
		Client->PushSubjectStaticData_AnyThread(Key, ULiveLinkAnimationRole::StaticClass(), MoveTemp(StaticData));
}


#undef LOCTEXT_NAMESPACE

