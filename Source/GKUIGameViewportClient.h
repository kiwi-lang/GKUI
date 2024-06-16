// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "CommonGameViewportClient.h"

#include "GKUIGameViewportClient.generated.h"

class UGameInstance;
class UObject;

UCLASS(BlueprintType)
class UGKUIGameViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()

public:
	UGKUIGameViewportClient();

	virtual void Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice = true) override;
};
