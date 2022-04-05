#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "ABoneControlAnimNode.h"
#include "BoneControlAnimGraph.generated.h"

UCLASS() 
class  UBoneControl_AnimGraphNode : public UAnimGraphNode_Base {
	GENERATED_BODY()
public:
		UPROPERTY(EditAnyWhere, Category = "Setting")
		FAnimNode_BoneControl Node;
public:
	//UBoneControl_AnimGraphNode();
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

};
