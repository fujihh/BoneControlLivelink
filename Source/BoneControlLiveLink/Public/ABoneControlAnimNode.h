#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "ABoneControlAnimNode.generated.h"

USTRUCT(BlueprintType) 
struct FAnimNode_BoneControl :public FAnimNode_Base {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		FPoseLink BasePose;

public:
	virtual  void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual  void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual  void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual  void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual	bool HasPreUpdate() const { return true; }
	//virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;

private:
	FBoneContainer boneContainer;
};

