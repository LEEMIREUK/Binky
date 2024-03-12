// Copyright Epic Games, Inc. All Rights Reserved.

#include "BinkyEditor.h"
#include "BinkyEditorStyle.h"
#include "BinkyEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

#include "LevelEditor.h"

static const FName BinkyEditorTabName("BinkyEditor");

#define LOCTEXT_NAMESPACE "FBinkyEditorModule"

FBinkyEditorModule* g_BinkyEditorModule = nullptr;

void FBinkyEditorModule::StartupModule()
{
	g_BinkyEditorModule = this;

	FBinkyEditorStyle::Initialize();
	FBinkyEditorStyle::ReloadTextures();

	FBinkyEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FBinkyEditorCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FBinkyEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FBinkyEditorCommands::Get().PlayTool,
		FExecuteAction::CreateRaw(this, &FBinkyEditorModule::PlayToolClicked),
		FCanExecuteAction());

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		LevelEditorModule.GetGlobalLevelEditorActions()->Append(PluginCommands.ToSharedRef());
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Play", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FBinkyEditorModule::AddBinkyToolbarExtension));

		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FBinkyEditorModule::ShutdownModule()
{
	FBinkyEditorStyle::Shutdown();

	FBinkyEditorCommands::Unregister();
}

void FBinkyEditorModule::PluginButtonClicked()
{
}

void FBinkyEditorModule::PlayToolClicked()
{
}

void FBinkyEditorModule::AddBinkyToolbarExtension(FToolBarBuilder& InBuilder)
{
	InBuilder.BeginSection("BinkyToolbar");

	TAttribute<FSlateIcon> IconAttribute = TAttribute<FSlateIcon>::Create(TAttribute<FSlateIcon>::FGetter::CreateLambda([this]()
		{
			return FMultiBoxSettings::UseSmallToolBarIcons.Get() ? FSlateIcon(FBinkyEditorStyle::GetStyleSetName(), "BinkyEditor.PluginAction") : FSlateIcon(FBinkyEditorStyle::GetStyleSetName(), "BinkyEditor.PluginAction");
		}));

	InBuilder.AddComboButton(
		FUIAction(),
		FOnGetContent::CreateStatic(&FBinkyEditorModule::GenerateBuildMenuContent),
		FText::FromString(TEXT("BinkyEditor")),
		FText::FromString(TEXT("BinkyEditor")),
		IconAttribute,
		false, NAME_None);

	InBuilder.EndSection();
}

TSharedRef<SWidget> FBinkyEditorModule::GenerateBuildMenuContent()
{
	const bool bShouldCloseWindowAfterMenuSelection = true;
	FMenuBuilder MenuBuilder(bShouldCloseWindowAfterMenuSelection, g_BinkyEditorModule->GetPluginCommands());

	MenuBuilder.BeginSection("Tools");
	{
		MenuBuilder.AddMenuEntry(FBinkyEditorCommands::Get().PlayTool, NAME_None, FText::FromString(TEXT("Play Tool")), LOCTEXT("Play Tool", "Open PlayTool"), FSlateIcon(FBinkyEditorStyle::GetStyleSetName(), "BinkyEditor.PlayTool"), NAME_None);
	}
	MenuBuilder.EndSection();
	
	return MenuBuilder.MakeWidget();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBinkyEditorModule, BinkyEditor)