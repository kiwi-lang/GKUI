// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKUITabButtonBase.h"

#include "CommonLazyImage.h"
#include "Common/GKUITabListWidgetBase.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKUITabButtonBase)

class UObject;
struct FSlateBrush;

void UGKUITabButtonBase::SetIconFromLazyObject(TSoftObjectPtr<UObject> LazyObject)
{
	if (LazyImage_Icon)
	{
		LazyImage_Icon->SetBrushFromLazyDisplayAsset(LazyObject);
	}
}

void UGKUITabButtonBase::SetIconBrush(const FSlateBrush& Brush)
{
	if (LazyImage_Icon)
	{
		LazyImage_Icon->SetBrush(Brush);
	}
}

void UGKUITabButtonBase::SetTabLabelInfo_Implementation(const FGKUITabDescriptor& TabLabelInfo)
{
	SetButtonText(TabLabelInfo.TabText);
	SetIconBrush(TabLabelInfo.IconBrush);
}

