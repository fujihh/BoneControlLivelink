#pragma once

#include "ILiveLinkClient.h"
#include "LiveLinkTypes.h"
#include "Roles/LiveLinkAnimationRole.h"
#include "Roles/LiveLinkAnimationTypes.h"


#define bone_pelvis			FName("pelvis")
#define bone_spine_03		FName("spine_03")
#define bone_head			FName("head")
#define bone_clavicle_l		FName("clavicle_l")
#define bone_upperarm_l		FName("upperarm_l")
#define bone_lowerarm_l		FName("lowerarm_l")
#define bone_hand_l			FName("hand_l")
#define bone_clavicle_r		FName("clavicle_r")
#define bone_upperarm_r		FName("upperarm_r")
#define bone_lowerarm_r		FName("lowerarm_r")
#define bone_hand_r			FName("hand_r")
#define bone_thigh_l		FName("thigh_l")
#define bone_calf_l			FName("calf_l")
#define bone_foot_l			FName("foot_l")
#define bone_thigh_r		FName("thigh_r")
#define bone_calf_r			FName("calf_r")
#define bone_foot_r			FName("foot_r")
class FBuildLiveLink {

public:
	
	FBuildLiveLink(ILiveLinkClient* iClient,FGuid iSourceGuid,FName iSubjectName);
	void PushStaticData();
	void PushFrameData();
	void FrameDataModify(TArray<FTransform>boneTransform);//deprecated
	void GetFrameData(TMap<FName,FTransform>bonesTransform);

private:

	TArray<FName>staticBonesName;
	TArray<int>staticBonesParentIndex;
	
	FLiveLinkStaticDataStruct StaticData;
	FLiveLinkSkeletonStaticData* SkeletonData;

	FLiveLinkFrameDataStruct FrameDataStruct;
	FLiveLinkAnimationFrameData *FrameData ;

	FLiveLinkSubjectKey Key;
	ILiveLinkClient* Client;
	//FGuid SourceGuid;
	//FName SubjectName;
};