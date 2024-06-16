// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "IndicatorLibrary.h"

#include "GKUIIndicatorManagerComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(IndicatorLibrary)

class AController;

UIndicatorLibrary::UIndicatorLibrary()
{
}

UGKUIIndicatorManagerComponent* UIndicatorLibrary::GetIndicatorManagerComponent(AController* Controller)
{
	return UGKUIIndicatorManagerComponent::GetComponent(Controller);
}

