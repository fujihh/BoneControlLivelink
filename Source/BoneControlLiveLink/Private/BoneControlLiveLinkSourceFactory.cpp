// Fill out your copyright notice in the Description page of Project Settings.


#include "BoneControlLiveLinkSourceFactory.h"
#include "SBoneControlLiveLinkSourceFactory.h"
#include "BoneControlLiveLinkSource.h"
#define LOCTEXT_NAMESPACE "BoneControlLiveLinkSourceFactory"

FText UBoneControlLiveLinkSourceFactory::GetSourceDisplayName() const {
	return LOCTEXT("SourceDisPlayerName", "BoneControlTest_LiveLink");
}

FText UBoneControlLiveLinkSourceFactory::GetSourceTooltip() const {
	return LOCTEXT("SourceToolTip", "Create a connection to Control bones");
}

TSharedPtr<SWidget> UBoneControlLiveLinkSourceFactory::BuildCreationPanel(FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const {
	return SNew(SBoneControlLiveLinkSourceFactory)
		.OnOkClicked(SBoneControlLiveLinkSourceFactory::FOnOkClicked::CreateUObject(this, &UBoneControlLiveLinkSourceFactory::OnOkClicked, InOnLiveLinkSourceCreated));
}

TSharedPtr<ILiveLinkSource> UBoneControlLiveLinkSourceFactory::CreateSource(const FString& InConnectionString) const {
	FIPv4Endpoint DeviceEndPoint;
	if (!FIPv4Endpoint::Parse(InConnectionString, DeviceEndPoint))
	{
		return TSharedPtr<ILiveLinkSource>();
	}

	return MakeShared<FBoneControlLiveLinkSource>(DeviceEndPoint);
}
void UBoneControlLiveLinkSourceFactory::OnOkClicked(FIPv4Endpoint InEndpoint, FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const
{
	InOnLiveLinkSourceCreated.ExecuteIfBound(MakeShared<FBoneControlLiveLinkSource>(InEndpoint), InEndpoint.ToString());
}
#undef LOCTEXT_NAMESPACE