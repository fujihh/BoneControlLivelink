#include"ABoneControlAnimNode.h"
#include "Animation/AnimInstanceProxy.h"

void FAnimNode_BoneControl::Initialize_AnyThread(const FAnimationInitializeContext& Context) {
	//BasePose.Initialize(Context);
	boneContainer = Context.AnimInstanceProxy->GetRequiredBones();

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