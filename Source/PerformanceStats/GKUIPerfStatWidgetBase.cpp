// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKUIPerfStatWidgetBase.h"

#include "Engine/GameInstance.h"
#include "Performance/GKUIPerformanceStatSubsystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUIPerfStatWidgetBase)

//////////////////////////////////////////////////////////////////////
// UGKUIPerfStatWidgetBase

UGKUIPerfStatWidgetBase::UGKUIPerfStatWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

double UGKUIPerfStatWidgetBase::FetchStatValue()
{
	if (CachedStatSubsystem == nullptr)
	{
		if (UWorld* World = GetWorld())
		{
			if (UGameInstance* GameInstance = World->GetGameInstance())
			{
				CachedStatSubsystem = GameInstance->GetSubsystem<UGKUIPerformanceStatSubsystem>();
			}
		}
	}

	if (CachedStatSubsystem)
	{
		return CachedStatSubsystem->GetCachedStat(StatToDisplay);
	}
	else
	{
		return 0.0;
	}
}

