// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "CommonUserWidget.h"

#include "GKUIPerfStatWidgetBase.generated.h"

enum class EGKUIDisplayablePerformanceStat : uint8;

class UGKUIPerformanceStatSubsystem;
class UObject;
struct FFrame;

/**
 * UGKUIPerfStatWidgetBase
 *
 * Base class for a widget that displays a single stat, e.g., FPS, ping, etc...
 */
 UCLASS(Abstract)
class UGKUIPerfStatWidgetBase : public UCommonUserWidget
{
public:
	UGKUIPerfStatWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	GENERATED_BODY()

public:
	// Returns the stat this widget is supposed to display
	UFUNCTION(BlueprintPure)
	EGKUIDisplayablePerformanceStat GetStatToDisplay() const
	{
		return StatToDisplay;
	}

	// Polls for the value of this stat (unscaled)
	UFUNCTION(BlueprintPure)
	double FetchStatValue();

protected:
	// Cached subsystem pointer
	UPROPERTY(Transient)
	TObjectPtr<UGKUIPerformanceStatSubsystem> CachedStatSubsystem;

	// The stat to display
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Display)
	EGKUIDisplayablePerformanceStat StatToDisplay;
 };
