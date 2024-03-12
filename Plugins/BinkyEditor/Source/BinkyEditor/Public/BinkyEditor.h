// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FBinkyEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	void PlayToolClicked();

public:
	void AddBinkyToolbarExtension(FToolBarBuilder& InBuilder);
	static TSharedRef<SWidget> GenerateBuildMenuContent();

public:
	TSharedPtr<class FUICommandList> GetPluginCommands() { return PluginCommands; }

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
