#include"FParseJson.h"
#include "DataManager.h"
#include "ABoneControlAnimNode.h"
#define LOCTEXT_NAMESPACE "ParseJosn"

//bonesTransformMap__temp;
FParseJson::FParseJson(TSharedPtr<FJsonObject> JsonObject) {
	Bones = JsonObject->GetObjectField("Bones");
	Frames = JsonObject->GetObjectField("Frames");
}
FParseJson::~FParseJson() {

}
void FParseJson::ParseBone() {
	//FAnimNode_BoneControl Node;

	//Node.GetBonesTransformMap();
	FName boneName;
	FVector boneTranslation;
	FRotator boneRotation;
	FVector boneScale(1.0, 1.0, 1.0);
	FQuat boneQuat;
	DataManager* dataManager_Singleton = DataManager::GetInstance();
	
	TMap<FName, FTransform>bonesTransformMap = dataManager_Singleton->GetBonesMap();
	TMap<FName, FName>boneTypeMap = dataManager_Singleton->getBoneTypeName();
	check(boneTypeMap.Num() != 0);
	
	FVector tempBoneTranslation;

	for (TPair<FString, TSharedPtr<FJsonValue>>& Bone : Bones->Values) {
		TSharedPtr<FJsonObject> singalBoneObject = Bone.Value->AsObject();
		boneName = boneTypeMap[FName(Bone.Key)];
		const TArray<TSharedPtr<FJsonValue>>* RotationArray;
		const TArray<TSharedPtr<FJsonValue>>* LocationArray;

		if (singalBoneObject->TryGetArrayField(TEXT("Rotation"), RotationArray)){
			if (RotationArray->Num() == 3) {
				isRotation = true;
				double X = (*RotationArray)[0]->AsNumber();
				double Y = (*RotationArray)[1]->AsNumber();
				double Z = (*RotationArray)[2]->AsNumber();
				boneRotation = FRotator(X, Y, Z);
			}
			else if (RotationArray->Num() == 4) {
				double X = (*RotationArray)[0]->AsNumber();
				double Y = (*RotationArray)[1]->AsNumber();
				double Z = (*RotationArray)[2]->AsNumber();
				double W = (*RotationArray)[3]->AsNumber();
				boneQuat = FQuat(X, Y, Z, W);
				isRotation = false;
			}
		}
		if (singalBoneObject->TryGetArrayField(TEXT("Position"), LocationArray)) {

			double X, Y, Z;
			if (bonesTransformMap.Num() > 0) {
				tempBoneTranslation = bonesTransformMap[boneName].GetTranslation() ;
				X = tempBoneTranslation.X;
				Y = tempBoneTranslation.Y;
				Z = tempBoneTranslation.Z;

			}
			else {

				X = (*LocationArray)[0]->AsNumber();
				Y = (*LocationArray)[1]->AsNumber();
				Z = (*LocationArray)[2]->AsNumber();
			}
			//boneTranslation = tempBoneTranslation;//get bones location by bone Container
			boneTranslation = FVector(X, Y, Z);//deprecated 
		}

		FTransform boneTransform = FTransform((isRotation ? boneRotation.Quaternion() : boneQuat), boneTranslation, boneScale);
		bonesTransform.Add(boneName, boneTransform);
		
	}
}



#undef LOCTEXT_NAMESPACE