// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "IndicatorLibrary.generated.h"

class AController;
class UGKUIIndicatorManagerComponent;
class UObject;
struct FFrame;

UCLASS()
class GKUI_API UIndicatorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UIndicatorLibrary();
	
	/**  */
	UFUNCTION(BlueprintCallable, Category = Indicator)
	static UGKUIIndicatorManagerComponent* GetIndicatorManagerComponent(AController* Controller);
};
