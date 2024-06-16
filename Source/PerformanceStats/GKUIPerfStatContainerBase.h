// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "CommonUserWidget.h"
#include "Performance/GKUIPerformanceStatTypes.h"

#include "GKUIPerfStatContainerBase.generated.h"

class UObject;
struct FFrame;

/**
 * UGKUIPerfStatsContainerBase
 *
 * Panel that contains a set of UGKUIPerfStatWidgetBase widgets and manages
 * their visibility based on user settings.
 */
 UCLASS(Abstract)
class UGKUIPerfStatContainerBase : public UCommonUserWidget
{
public:
	UGKUIPerfStatContainerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	GENERATED_BODY()

	//~UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//~End of UUserWidget interface

	UFUNCTION(BlueprintCallable)
	void UpdateVisibilityOfChildren();

protected:
	// Are we showing text or graph stats?
	UPROPERTY(EditAnywhere, Category=Display)
	EGKUIStatDisplayMode StatDisplayModeFilter = EGKUIStatDisplayMode::TextAndGraph;
};
