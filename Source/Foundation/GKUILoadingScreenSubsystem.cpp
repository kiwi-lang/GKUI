// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "Foundation/GKUILoadingScreenSubsystem.h"

#include "Blueprint/UserWidget.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUILoadingScreenSubsystem)

class UUserWidget;

//////////////////////////////////////////////////////////////////////
// UGKUILoadingScreenSubsystem

UGKUILoadingScreenSubsystem::UGKUILoadingScreenSubsystem()
{
}

void UGKUILoadingScreenSubsystem::SetLoadingScreenContentWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (LoadingScreenWidgetClass != NewWidgetClass)
	{
		LoadingScreenWidgetClass = NewWidgetClass;

		OnLoadingScreenWidgetChanged.Broadcast(LoadingScreenWidgetClass);
	}
}

TSubclassOf<UUserWidget> UGKUILoadingScreenSubsystem::GetLoadingScreenContentWidget() const
{
	return LoadingScreenWidgetClass;
}

