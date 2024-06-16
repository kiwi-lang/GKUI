// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKUIWidgetFactory.h"
#include "Templates/SubclassOf.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUIWidgetFactory)

class UUserWidget;

TSubclassOf<UUserWidget> UGKUIWidgetFactory::FindWidgetClassForData_Implementation(const UObject* Data) const
{
	return TSubclassOf<UUserWidget>();
}
