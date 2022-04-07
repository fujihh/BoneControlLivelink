#include"ABoneControlAnimNode.h"
#include "Animation/AnimInstanceProxy.h"

#include "Misc/FileHelper.h"

#include "DataManager.h"

//extern "C" TMap<FName, FTransform>bonesTransformMap__temp;
FAnimNode_BoneControl::FAnimNode_BoneControl() {

}


void FAnimNode_BoneControl::Initialize_AnyThread(const FAnimationInitializeContext& Context) {
	//BasePose.Initialize(Context);
	//bonesTransformMap;
	//TArray<FString>temp;
	FBoneContainer boneContainer = Context.AnimInstanceProxy->GetRequiredBones();  
	TArray<FName>bonesName;
	Context.AnimInstanceProxy->GetSkelMeshComponent()->GetBoneNames(bonesName); // get skeleton's Name;
	TArray<FTransform>bonesTransform = boneContainer.GetRefPoseArray(); //get each skeleton's transform;
	if (bonesName.Num() == bonesTransform.Num()) {
		for (int i = 0; i < bonesName.Num(); i++) {
			bonesTransformMap.Add(bonesName[i], bonesTransform[i]);
			//bonesTransformMap__temp.Add(bonesName[i], bonesTransform[i]);
			//temp.Add((bonesName[i].ToString()) + " : " + bonesTransform[i].GetTranslation().ToString());
		}
		DataManager* dataManager_Singleton = DataManager::GetInstance();
		dataManager_Singleton->SetBonesMap(bonesTransformMap);
		//m_DataManager.SetBonesMap(bonesTransformMap);
	}
	//bonesTransformMap__temp = bonesTransformMap;
	/*FString filepath = FPaths::GameSourceDir() + TEXT("BoneTranslation.txt");
	filepath = FPaths::ConvertRelativePathToFull(filepath);
	FFileHelper::SaveStringArrayToFile(temp, *filepath, FFileHelper::EEncodingOptions::ForceUTF8);*/
	
}

void FAnimNode_BoneControl::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) {
	BasePose.CacheBones(Context);
}

void FAnimNode_BoneControl::Evaluate_AnyThread(FPoseContext& Ouput) {

}

void FAnimNode_BoneControl::Update_AnyThread(const FAnimationUpdateContext& Context) {

}
void FAnimNode_BoneControl::GatherDebugData(FNodeDebugData& DebugData) {

}
TMap<FName, FTransform> FAnimNode_BoneControl::GetBonesTransformMap() {
	
	return bonesTransformMap;
}