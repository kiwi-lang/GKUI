// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "GKUIWidgetFactory.h"
#include "Templates/SubclassOf.h"
#include "UObject/SoftObjectPtr.h"

#include "GKUIWidgetFactory_Class.generated.h"

class UObject;
class UUserWidget;

UCLASS()
class GKUI_API UGKUIWidgetFactory_Class : public UGKUIWidgetFactory
{
	GENERATED_BODY()

public:
	UGKUIWidgetFactory_Class() { }

	virtual TSubclassOf<UUserWidget> FindWidgetClassForData_Implementation(const UObject* Data) const override;
	
protected:
	UPROPERTY(EditAnywhere, Category = ListEntries, meta = (AllowAbstract))
	TMap<TSoftClassPtr<UObject>, TSubclassOf<UUserWidget>> EntryWidgetForClass;
};
