// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKUIWeaponUserInterface.h"

#include "Equipment/GKUIEquipmentManagerComponent.h"
#include "GameFramework/Pawn.h"
#include "Weapons/GKUIWeaponInstance.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUIWeaponUserInterface)

struct FGeometry;

UGKUIWeaponUserInterface::UGKUIWeaponUserInterface(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGKUIWeaponUserInterface::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGKUIWeaponUserInterface::NativeDestruct()
{
	Super::NativeDestruct();
}

void UGKUIWeaponUserInterface::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (APawn* Pawn = GetOwningPlayerPawn())
	{
		if (UGKUIEquipmentManagerComponent* EquipmentManager = Pawn->FindComponentByClass<UGKUIEquipmentManagerComponent>())
		{
			if (UGKUIWeaponInstance* NewInstance = EquipmentManager->GetFirstInstanceOfType<UGKUIWeaponInstance>())
			{
				if (NewInstance != CurrentInstance && NewInstance->GetInstigator() != nullptr)
				{
					UGKUIWeaponInstance* OldWeapon = CurrentInstance;
					CurrentInstance = NewInstance;
					RebuildWidgetFromWeapon();
					OnWeaponChanged(OldWeapon, CurrentInstance);
				}
			}
		}
	}
}

void UGKUIWeaponUserInterface::RebuildWidgetFromWeapon()
{
	
}

