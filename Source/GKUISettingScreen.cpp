// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKUISettingScreen.h"

#include "Input/CommonUIInputTypes.h"
#include "Player/GKUILocalPlayer.h"
#include "Settings/GKUIGameSettingRegistry.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUISettingScreen)

class UGameSettingRegistry;

void UGKUISettingScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BackHandle = RegisterUIActionBinding(FBindUIActionArgs(BackInputActionData, true, FSimpleDelegate::CreateUObject(this, &ThisClass::HandleBackAction)));
	ApplyHandle = RegisterUIActionBinding(FBindUIActionArgs(ApplyInputActionData, true, FSimpleDelegate::CreateUObject(this, &ThisClass::HandleApplyAction)));
	CancelChangesHandle = RegisterUIActionBinding(FBindUIActionArgs(CancelChangesInputActionData, true, FSimpleDelegate::CreateUObject(this, &ThisClass::HandleCancelChangesAction)));
}

UGameSettingRegistry* UGKUISettingScreen::CreateRegistry()
{
	UGKUIGameSettingRegistry* NewRegistry = NewObject<UGKUIGameSettingRegistry>();

	if (UGKUILocalPlayer* LocalPlayer = CastChecked<UGKUILocalPlayer>(GetOwningLocalPlayer()))
	{
		NewRegistry->Initialize(LocalPlayer);
	}

	return NewRegistry;
}

void UGKUISettingScreen::HandleBackAction()
{
	if (AttemptToPopNavigation())
	{
		return;
	}

	ApplyChanges();

	DeactivateWidget();
}

void UGKUISettingScreen::HandleApplyAction()
{
	ApplyChanges();
}

void UGKUISettingScreen::HandleCancelChangesAction()
{
	CancelChanges();
}

void UGKUISettingScreen::OnSettingsDirtyStateChanged_Implementation(bool bSettingsDirty)
{
	if (bSettingsDirty)
	{
		if (!GetActionBindings().Contains(ApplyHandle))
		{
			AddActionBinding(ApplyHandle);
		}
		if (!GetActionBindings().Contains(CancelChangesHandle))
		{
			AddActionBinding(CancelChangesHandle);
		}
	}
	else
	{
		RemoveActionBinding(ApplyHandle);
		RemoveActionBinding(CancelChangesHandle);
	}
}
