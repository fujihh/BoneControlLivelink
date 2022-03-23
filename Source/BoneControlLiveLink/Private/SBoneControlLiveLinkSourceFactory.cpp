// Fill out your copyright notice in the Description page of Project Settings.


#include "SBoneControlLiveLinkSourceFactory.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "BoneControlLiveLinkSourceEditor"

void SBoneControlLiveLinkSourceFactory::Construct(const FArguments& Args) {
	OkClicked = Args._OnOkClicked;

	FIPv4Endpoint Endpoint;
	//Endpoint.Address = FIPv4Address::Any;
	Endpoint.Address = FIPv4Address(127, 0, 0, 1);
	Endpoint.Port = 8010;

	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(250)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.HAlign(HAlign_Left)
		.FillWidth(0.5f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("MyPortNumber", "Port Number"))
		]
	+ SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		.FillWidth(0.5f)
		[
			SAssignNew(EditabledText, SEditableTextBox)
			.Text(FText::FromString(Endpoint.ToString()))
		.OnTextCommitted(this, &SBoneControlLiveLinkSourceFactory::OnEndpointChanged)
		]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Right)
		.AutoHeight()
		[
			SNew(SButton)
			.OnClicked(this, &SBoneControlLiveLinkSourceFactory::OnOkClicked)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Ok", "Ok"))
		]
		]
		]
		];

}

void SBoneControlLiveLinkSourceFactory::OnEndpointChanged(const FText& NewValue, ETextCommit::Type) {
	TSharedPtr<SEditableTextBox> EditabledTextPin = EditabledText.Pin();
	if (EditabledTextPin.IsValid()) {
		FIPv4Endpoint Endpoint;
		if (!FIPv4Endpoint::Parse(NewValue.ToString(), Endpoint))
		{
			Endpoint.Address = FIPv4Address::Any;
			Endpoint.Port = 8010;
			EditabledTextPin->SetText(FText::FromString(Endpoint.ToString()));
		}
	}
}

FReply SBoneControlLiveLinkSourceFactory::OnOkClicked() {
	TSharedPtr<SEditableTextBox> EditabledTextPin = EditabledText.Pin();
	if (EditabledTextPin.IsValid())
	{
		FIPv4Endpoint Endpoint;
		if (FIPv4Endpoint::Parse(EditabledTextPin->GetText().ToString(), Endpoint))
		{
			OkClicked.ExecuteIfBound(Endpoint);
		}
	}
	return FReply::Handled();
}
#undef LOCTEXT_NAMESPACE