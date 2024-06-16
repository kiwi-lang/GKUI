// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "UObject/Object.h"

#include "GKUIWidgetFactory.generated.h"

template <class TClass> class TSubclassOf;

class UUserWidget;
struct FFrame;

UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class GKUI_API UGKUIWidgetFactory : public UObject
{
	GENERATED_BODY()

public:
	UGKUIWidgetFactory() { }

	UFUNCTION(BlueprintNativeEvent)
	TSubclassOf<UUserWidget> FindWidgetClassForData(const UObject* Data) const;
};
