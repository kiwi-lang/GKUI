// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "CommonUserWidget.h"

#include "GKUIWeaponUserInterface.generated.h"

class UGKUIWeaponInstance;
class UObject;
struct FGeometry;

UCLASS()
class UGKUIWeaponUserInterface : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UGKUIWeaponUserInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponChanged(UGKUIWeaponInstance* OldWeapon, UGKUIWeaponInstance* NewWeapon);

private:
	void RebuildWidgetFromWeapon();

private:
	UPROPERTY(Transient)
	TObjectPtr<UGKUIWeaponInstance> CurrentInstance;
};
