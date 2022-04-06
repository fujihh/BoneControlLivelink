#include"FBuildLiveLink.h"

#define LOCTEXT_NAMESPACE "BuildLiveLink"

FBuildLiveLink::FBuildLiveLink(ILiveLinkClient* iClient, FGuid iSourceGuid, FName iSubjectName){
	staticBonesName.Add(bone_pelvis);
	staticBonesName.Add(bone_spine_03);
	staticBonesName.Add(bone_head);
	staticBonesName.Add(bone_clavicle_l);
	staticBonesName.Add(bone_upperarm_l);
	staticBonesName.Add(bone_lowerarm_l);
	staticBonesName.Add(bone_hand_l);
	staticBonesName.Add(bone_clavicle_r);
	staticBonesName.Add(bone_upperarm_r);
	staticBonesName.Add(bone_lowerarm_r);
	staticBonesName.Add(bone_hand_r);
	staticBonesName.Add(bone_thigh_l);
	staticBonesName.Add(bone_calf_l);
	staticBonesName.Add(bone_foot_l);
	staticBonesName.Add(bone_thigh_r);
	staticBonesName.Add(bone_calf_r);
	staticBonesName.Add(bone_foot_r);

	staticBonesParentIndex.Add(0);
	staticBonesParentIndex.Add(0);
	staticBonesParentIndex.Add(1);
	
	staticBonesParentIndex.Add(1);
	staticBonesParentIndex.Add(3);
	staticBonesParentIndex.Add(4);
	staticBonesParentIndex.Add(5);

	staticBonesParentIndex.Add(1);
	staticBonesParentIndex.Add(7);
	staticBonesParentIndex.Add(8);
	staticBonesParentIndex.Add(9);
	
	staticBonesParentIndex.Add(0);
	staticBonesParentIndex.Add(11);
	staticBonesParentIndex.Add(12);
	
	staticBonesParentIndex.Add(0);
	staticBonesParentIndex.Add(14);
	staticBonesParentIndex.Add(15);

	StaticData = FLiveLinkStaticDataStruct(FLiveLinkSkeletonStaticData::StaticStruct());
	SkeletonData = StaticData.Cast<FLiveLinkSkeletonStaticData>();

	FrameDataStruct = FLiveLinkFrameDataStruct(FLiveLinkAnimationFrameData::StaticStruct());
	FrameData = FrameDataStruct.Cast<FLiveLinkAnimationFrameData>();

	SkeletonData->SetBoneNames(staticBonesName);
	SkeletonData->SetBoneParents(staticBonesParentIndex);

	this->Client = iClient;
	//this->SourceGuid = iSourceGuid;
	//this->SubjectName = iSubjectName;
	Key = FLiveLinkSubjectKey(iSourceGuid, iSubjectName);
	if (Client) {
		Client->PushSubjectStaticData_AnyThread(Key, ULiveLinkAnimationRole::StaticClass(), MoveTemp(StaticData));
	}
}

void FBuildLiveLink::PushFrameData() {
	if (Client) {
		Client->PushSubjectFrameData_AnyThread(Key, MoveTemp(FrameDataStruct));
	}
}

void FBuildLiveLink::PushStaticData() {
	//FLiveLinkSubjectKey Key = FLiveLinkSubjectKey(SourceGuid, SubjectName);
	if (Client) {
		Client->PushSubjectStaticData_AnyThread(Key, ULiveLinkAnimationRole::StaticClass(), MoveTemp(StaticData));
	}
}

void FBuildLiveLink::FrameDataModify(TArray<FTransform>boneTransform) {
	int index = boneTransform.Num();
	FrameData->Transforms.SetNumUninitialized(index);
	for (int i = 0; i < index; i++) {
		FrameData->Transforms[i] = boneTransform[i];
	}
}

void FBuildLiveLink::GetFrameData(TMap<FName, FTransform>bonesTransform) {
	TArray<FTransform>frameTransform;
	for (int i = 0; i < staticBonesName.Num(); i++) {	
		//check(bonesTransform[staticBonesName[i]]);
		frameTransform.Add(bonesTransform[staticBonesName[i]]);
	}

	FrameData->Transforms.SetNumUninitialized(frameTransform.Num());
	FrameData->Transforms = frameTransform;
	//return frameTransform;
	if (Client) {
		Client->PushSubjectFrameData_AnyThread(Key, MoveTemp(FrameDataStruct));
	}

}

#undef LOCTEXT_NAMESPACE
