#include "BoneControlAnimGraph.h"


#define LOCTEXT_NAMESPACE "BoneControlAnimGraph"


FLinearColor UBoneControl_AnimGraphNode::GetNodeTitleColor()const {
	return FLinearColor(0.7f, 0.7f, 0.7f);

}

FText UBoneControl_AnimGraphNode::GetTooltipText()const {
	return LOCTEXT("BoneControl", "BoneControl");
}
FText UBoneControl_AnimGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType)const {
	return LOCTEXT("BoneControl_BaseAnimGraphNode", "BoneControl_BaseAnimGraphNode");
}
#undef LOCTEXT_NAMESPACE