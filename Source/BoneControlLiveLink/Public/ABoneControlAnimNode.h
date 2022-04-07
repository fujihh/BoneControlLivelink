#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "FParseJson.h"
#include "ABoneControlAnimNode.generated.h"

//extern "C" TMap<FName, FTransform>bonesTransformMap__temp;

USTRUCT(BlueprintType) 
struct BONECONTROLLIVELINK_API  FAnimNode_BoneControl :public FAnimNode_Base {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		FPoseLink BasePose;

public:

	FAnimNode_BoneControl();
	//friend class FParseJson;
	virtual  void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual  void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual  void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual  void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual	bool HasPreUpdate() const { return true; }
	//virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
	TMap<FName, FTransform>GetBonesTransformMap();
	//static FAnimNode_BoneControl* GetInstance(const FString& value);
private:
	//FBoneContainer boneContainer;
	TMap<FName, FTransform>bonesTransformMap;

};

