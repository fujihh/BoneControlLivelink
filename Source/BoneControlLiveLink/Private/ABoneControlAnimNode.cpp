#include"ABoneControlAnimNode.h"
#include "Animation/AnimInstanceProxy.h"

#include "Misc/FileHelper.h"

#include "DataManager.h"


void judgeBoneType(int bonesnum);
//#define VNAME(value) (#value)
//extern "C" TMap<FName, FTransform>bonesTransformMap__temp;
FAnimNode_BoneControl::FAnimNode_BoneControl() {

}


void FAnimNode_BoneControl::Initialize_AnyThread(const FAnimationInitializeContext& Context) {
	//BasePose.Initialize(Context);
	//bonesTransformMap;
	TArray<FString>temp;

	FBoneContainer boneContainer = Context.AnimInstanceProxy->GetRequiredBones();  
	
	
	//FString boneTypeName = VNAME(boneContainer.GetSkeletonAsset());
	//USkeleton *currentSkelton = boneContainer.GetSkeletonAsset();
	//FString boneTypeName = typeid(currentSkelton).name();

	TArray<FName>bonesName;
	Context.AnimInstanceProxy->GetSkelMeshComponent()->GetBoneNames(bonesName); // get skeleton's Name;
	TArray<FTransform>bonesTransform = boneContainer.GetRefPoseArray(); //get each skeleton's transform;
	if (bonesName.Num() == bonesTransform.Num()) {
		for (int i = 0; i < bonesName.Num(); i++) {
			bonesTransformMap.Add(bonesName[i], bonesTransform[i]);
			//bonesTransformMap__temp.Add(bonesName[i], bonesTransform[i]);
			temp.Add((bonesName[i].ToString()) + " : " + bonesTransform[i].GetRotation().ToString());
		}
		DataManager* dataManager_Singleton = DataManager::GetInstance();
		dataManager_Singleton->SetBonesMap(bonesTransformMap);
		judgeBoneType(bonesName.Num());
		UE_LOG(LogTemp, Log, TEXT("num : %d"),boneContainer.GetNumBones());
		//m_DataManager.SetBonesMap(bonesTransformMap);
	}
	//bonesTransformMap__temp = bonesTransformMap;
	FString filepath = FPaths::GameSourceDir() + TEXT("BoneTranslation.txt");
	filepath = FPaths::ConvertRelativePathToFull(filepath);
	FFileHelper::SaveStringArrayToFile(temp, *filepath, FFileHelper::EEncodingOptions::ForceUTF8);
	
}

void FAnimNode_BoneControl::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) {
	BasePose.CacheBones(Context);
}

void FAnimNode_BoneControl::Evaluate_AnyThread(FPoseContext& Ouput) {
	FBoneContainer boneContainer= Ouput.Pose.GetBoneContainer();
	boneContainer.GetCalculatedForLOD();
	UE_LOG(LogTemp, Log, TEXT("LOD : %d , Bone Num : %d"), boneContainer.GetCalculatedForLOD(), boneContainer.GetNumBones());
}

void FAnimNode_BoneControl::Update_AnyThread(const FAnimationUpdateContext& Context) {

}
void FAnimNode_BoneControl::GatherDebugData(FNodeDebugData& DebugData) {

}
TMap<FName, FTransform> FAnimNode_BoneControl::GetBonesTransformMap() {
	
	return bonesTransformMap;
}

void judgeBoneType(int bonesnum) {
	DataManager* dataManager_Singleton = DataManager::GetInstance();
	if (bonesnum == 68) {
		dataManager_Singleton->setBoneSelected(0);
	}
	else if(bonesnum == 178	){
		dataManager_Singleton->setBoneSelected(2);
	}
	else {
		dataManager_Singleton->setBoneSelected(1);

	}
}
