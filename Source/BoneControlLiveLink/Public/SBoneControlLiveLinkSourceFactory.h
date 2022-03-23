// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Input/Reply.h"
#include "Types/SlateEnums.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "CoreMinimal.h"

/**
 *
 */
class  SBoneControlLiveLinkSourceFactory :public SCompoundWidget
{
public:
	DECLARE_DELEGATE_OneParam(FOnOkClicked, FIPv4Endpoint);

	SLATE_BEGIN_ARGS(SBoneControlLiveLinkSourceFactory) {}
	SLATE_EVENT(FOnOkClicked, OnOkClicked)
		SLATE_END_ARGS()

		void Construct(const FArguments& Args);

private:
	void OnEndpointChanged(const FText& NewValue, ETextCommit::Type);

	FReply OnOkClicked();

	TWeakPtr<SEditableTextBox> EditabledText;
	FOnOkClicked OkClicked;
};
