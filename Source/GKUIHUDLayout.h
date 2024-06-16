// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "GKUIActivatableWidget.h"

#include "GKUIHUDLayout.generated.h"

class UCommonActivatableWidget;
class UObject;


/**
 * UGKUIHUDLayout
 *
 *	Widget used to lay out the player's HUD (typically specified by an Add Widgets action in the experience)
 */
UCLASS(Abstract, BlueprintType, Blueprintable, Meta = (DisplayName = "GKUI HUD Layout", Category = "GKUI|HUD"))
class UGKUIHUDLayout : public UGKUIActivatableWidget
{
	GENERATED_BODY()

public:

	UGKUIHUDLayout(const FObjectInitializer& ObjectInitializer);

	void NativeOnInitialized() override;

protected:
	void HandleEscapeAction();

	UPROPERTY(EditDefaultsOnly)
	TSoftClassPtr<UCommonActivatableWidget> EscapeMenuClass;
};
