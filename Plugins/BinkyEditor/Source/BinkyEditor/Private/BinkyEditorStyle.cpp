// Copyright Epic Games, Inc. All Rights Reserved.

#include "BinkyEditorStyle.h"
#include "BinkyEditor.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FBinkyEditorStyle::StyleInstance = nullptr;

void FBinkyEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FBinkyEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FBinkyEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("BinkyEditorStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FBinkyEditorStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("BinkyEditorStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("BinkyEditor")->GetBaseDir() / TEXT("Resources"));

	Style->Set("BinkyEditor.PluginAction", new IMAGE_BRUSH(TEXT("BinkyImage"), Icon40x40));
	Style->Set("BinkyEditor.PlayTool", new IMAGE_BRUSH(TEXT("PlayButtonImage"), Icon40x40));

	return Style;
}

void FBinkyEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FBinkyEditorStyle::Get()
{
	return *StyleInstance;
}
