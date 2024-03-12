// Copyright Epic Games, Inc. All Rights Reserved.

#include "BinkyEditorCommands.h"

#define LOCTEXT_NAMESPACE "FBinkyEditorModule"

void FBinkyEditorCommands::RegisterCommands()
{
	// Command ID , Name, Description
	UI_COMMAND(PluginAction, "BinkyEditor", "Binky Editor Tool", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(PlayTool, "PlayTool", "Open Play Tool", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
