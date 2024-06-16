// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "GKUITabListWidgetBase.h"
#include "Foundation/GKUIButtonBase.h"

#include "GKUITabButtonBase.generated.h"

class UCommonLazyImage;
class UObject;
struct FFrame;
struct FSlateBrush;

UCLASS(Abstract, Blueprintable, meta = (DisableNativeTick))
class GKUI_API UGKUITabButtonBase : public UGKUIButtonBase, public IGKUITabButtonInterface
{
	GENERATED_BODY()

public:

	void SetIconFromLazyObject(TSoftObjectPtr<UObject> LazyObject);
	void SetIconBrush(const FSlateBrush& Brush);

protected:

	UFUNCTION()
	virtual void SetTabLabelInfo_Implementation(const FGKUITabDescriptor& TabLabelInfo) override;

private:

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;
};
