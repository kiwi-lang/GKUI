// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "CommonListView.h"

#include "GKUIListView.generated.h"

class UUserWidget;
class ULocalPlayer;
class UGKUIWidgetFactory;

UCLASS(meta = (DisableNativeTick))
class GKUI_API UGKUIListView : public UCommonListView
{
	GENERATED_BODY()

public:
	UGKUIListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#if WITH_EDITOR
	virtual void ValidateCompiledDefaults(IWidgetCompilerLog& InCompileLog) const override;
#endif

protected:
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;
	//virtual bool OnIsSelectableOrNavigableInternal(UObject* SelectedItem) override;

protected:
	UPROPERTY(EditAnywhere, Instanced, Category="Entry Creation")
	TArray<TObjectPtr<UGKUIWidgetFactory>> FactoryRules;
};
