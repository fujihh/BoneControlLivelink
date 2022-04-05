#include"ABoneControlAnimNode.h"
#include "Animation/AnimInstanceProxy.h"

void FAnimNode_BoneControl::Initialize_AnyThread(const FAnimationInitializeContext& Context) {
	//BasePose.Initialize(Context);
	TMap<FName, FTransform>bonesTransformMap;
	FBoneContainer boneContainer = Context.AnimInstanceProxy->GetRequiredBones();  
	TArray<FName>bonesName;
	Context.AnimInstanceProxy->GetSkelMeshComponent()->GetBoneNames(bonesName); // get skeleton's Name;
	TArray<FTransform>bonesTransform = boneContainer.GetRefPoseArray(); //get each skeleton's transform;
	if (bonesName.Num() == bonesTransform.Num()) {
		for (int i = 0; i < bonesName.Num(); i++) {
			bonesTransformMap.Add(bonesName[i], bonesTransform[i]);
		}
	}
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
