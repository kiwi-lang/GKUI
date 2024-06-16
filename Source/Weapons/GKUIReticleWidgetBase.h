// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "CommonUserWidget.h"

#include "GKUIReticleWidgetBase.generated.h"

class UGKUIInventoryItemInstance;
class UGKUIWeaponInstance;
class UObject;
struct FFrame;

UCLASS(Abstract)
class UGKUIReticleWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UGKUIReticleWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponInitialized();

	UFUNCTION(BlueprintCallable)
	void InitializeFromWeapon(UGKUIWeaponInstance* InWeapon);

	/** Returns the current weapon's diametrical spread angle, in degrees */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float ComputeSpreadAngle() const;

	/** Returns the current weapon's maximum spread radius in screenspace units (pixels) */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float ComputeMaxScreenspaceSpreadRadius() const;

	/**
	 * Returns true if the current weapon is at 'first shot accuracy'
	 * (the weapon allows it and it is at min spread)
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasFirstShotAccuracy() const;

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UGKUIWeaponInstance> WeaponInstance;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UGKUIInventoryItemInstance> InventoryInstance;
};
