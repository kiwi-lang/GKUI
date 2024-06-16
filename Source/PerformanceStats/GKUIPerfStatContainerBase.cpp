// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKUIPerfStatContainerBase.h"

#include "Blueprint/WidgetTree.h"
#include "GKUIPerfStatWidgetBase.h"
#include "Settings/GKUISettingsLocal.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUIPerfStatContainerBase)

//////////////////////////////////////////////////////////////////////
// UGKUIPerfStatsContainerBase

UGKUIPerfStatContainerBase::UGKUIPerfStatContainerBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGKUIPerfStatContainerBase::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateVisibilityOfChildren();

	UGKUISettingsLocal::Get()->OnPerfStatDisplayStateChanged().AddUObject(this, &ThisClass::UpdateVisibilityOfChildren);
}

void UGKUIPerfStatContainerBase::NativeDestruct()
{
	UGKUISettingsLocal::Get()->OnPerfStatDisplayStateChanged().RemoveAll(this);

	Super::NativeDestruct();
}

void UGKUIPerfStatContainerBase::UpdateVisibilityOfChildren()
{
	UGKUISettingsLocal* UserSettings = UGKUISettingsLocal::Get();

	const bool bShowTextWidgets = (StatDisplayModeFilter == EGKUIStatDisplayMode::TextOnly) || (StatDisplayModeFilter == EGKUIStatDisplayMode::TextAndGraph);
	const bool bShowGraphWidgets = (StatDisplayModeFilter == EGKUIStatDisplayMode::GraphOnly) || (StatDisplayModeFilter == EGKUIStatDisplayMode::TextAndGraph);
	
	check(WidgetTree);
	WidgetTree->ForEachWidget([&](UWidget* Widget)
	{
		if (UGKUIPerfStatWidgetBase* TypedWidget = Cast<UGKUIPerfStatWidgetBase>(Widget))
		{
			const EGKUIStatDisplayMode SettingMode = UserSettings->GetPerfStatDisplayState(TypedWidget->GetStatToDisplay());

			bool bShowWidget = false;
			switch (SettingMode)
			{
			case EGKUIStatDisplayMode::Hidden:
				bShowWidget = false;
				break;
			case EGKUIStatDisplayMode::TextOnly:
				bShowWidget = bShowTextWidgets;
				break;
			case EGKUIStatDisplayMode::GraphOnly:
				bShowWidget = bShowGraphWidgets;
				break;
			case EGKUIStatDisplayMode::TextAndGraph:
				bShowWidget = bShowTextWidgets || bShowGraphWidgets;
				break;
			}

			TypedWidget->SetVisibility(bShowWidget ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
		}
	});
}

