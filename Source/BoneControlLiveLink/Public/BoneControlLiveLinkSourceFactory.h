#pragma once

#include "CoreMinimal.h"
#include "LiveLinkSourceFactory.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "BoneControlLiveLinkSourceFactory.generated.h"

UCLASS()
class BONECONTROLLIVELINK_API UBoneControlLiveLinkSourceFactory : public ULiveLinkSourceFactory
{

public:
	GENERATED_BODY()
	virtual FText GetSourceDisplayName() const override;
	virtual FText GetSourceTooltip() const override;

	virtual EMenuType GetMenuType() const override { return EMenuType::SubPanel; }
	virtual TSharedPtr<SWidget>BuildCreationPanel(FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated)const override;

	TSharedPtr<ILiveLinkSource> CreateSource(const FString& InConnectionString) const override;

private:
	void OnOkClicked(FIPv4Endpoint Endpoint, FOnLiveLinkSourceCreated OnLiveLinkSourceCreated)const;

};
