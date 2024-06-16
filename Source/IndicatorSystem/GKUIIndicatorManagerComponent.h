// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "Components/ControllerComponent.h"

#include "GKUIIndicatorManagerComponent.generated.h"

class AController;
class UIndicatorDescriptor;
class UObject;
struct FFrame;

/**
 * @class UGKUIIndicatorManagerComponent
 */
UCLASS(BlueprintType, Blueprintable)
class GKUI_API UGKUIIndicatorManagerComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UGKUIIndicatorManagerComponent(const FObjectInitializer& ObjectInitializer);

	static UGKUIIndicatorManagerComponent* GetComponent(AController* Controller);

	UFUNCTION(BlueprintCallable, Category = Indicator)
	void AddIndicator(UIndicatorDescriptor* IndicatorDescriptor);
	
	UFUNCTION(BlueprintCallable, Category = Indicator)
	void RemoveIndicator(UIndicatorDescriptor* IndicatorDescriptor);

	DECLARE_EVENT_OneParam(UGKUIIndicatorManagerComponent, FIndicatorEvent, UIndicatorDescriptor* Descriptor)
	FIndicatorEvent OnIndicatorAdded;
	FIndicatorEvent OnIndicatorRemoved;

	const TArray<UIndicatorDescriptor*>& GetIndicators() const { return Indicators; }

private:
	UPROPERTY()
	TArray<TObjectPtr<UIndicatorDescriptor>> Indicators;
};
