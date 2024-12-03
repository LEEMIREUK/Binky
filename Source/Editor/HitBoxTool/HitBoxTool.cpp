#include "HitBoxTool.h"
#include "ToolMenus.h"

IMPLEMENT_MODULE(FHitBoxTool, HitBoxTool);

void FHitBoxTool::StartupModule()
{
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FHitBoxTool::RegisterHitBoxToolMenu));
}

void FHitBoxTool::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
}

void FHitBoxTool::RegisterHitBoxToolMenu()
{
    UToolMenu* MainMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
    FToolMenuSection& Section = MainMenu->AddSection("EditorTool", FText::FromString("Editor Tool"));
    Section.AddMenuEntry(
        "EditorTool",
        FText::FromString("Editor Tool"),
        FText::FromString("This is editor tool."),
        FSlateIcon(),
        FUIAction()
    );

    UToolMenu* SubMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.EditorTool");
    FToolMenuSection& SubMenuSection = SubMenu->AddSection("HitBoxTool", FText::FromString("HitBox Tool"));
    SubMenuSection.AddMenuEntry(
        "HitBoxTool",
        FText::FromString("HitBox Tool"),
        FText::FromString("Open HitBox Tool"),
        FSlateIcon(),
        FUIAction(FExecuteAction::CreateRaw(this, &FHitBoxTool::OnClickHitBoxTool))
    );
}

void FHitBoxTool::OnClickHitBoxTool()
{

}
