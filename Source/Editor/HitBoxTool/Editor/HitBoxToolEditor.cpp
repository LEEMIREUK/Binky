#include "HitBoxToolEditor.h"
#include "HitBoxToolManager.h"
#include "HitBoxToolViewport.h"
#include "../Details/HitBoxToolDetails.h"

#include "PersonaModule.h"
#include "IPersonaToolkit.h"
#include "PreviewScene.h"

#define LOCTEXT_NAMESPACE "HitBoxToolEditor"

const FName FHitBoxToolEditor::ViewportTabId(FName("HitBoxToolEditor_Viewport"));
const FName FHitBoxToolEditor::TimelineTabId(FName("HitBoxToolEditor_Timeline"));
const FName FHitBoxToolEditor::DetailsTabId(FName("HitBoxToolEditor_Details"));

FHitBoxToolEditor::FHitBoxToolEditor()
{
}

FHitBoxToolEditor::~FHitBoxToolEditor()
{
	Viewport.Reset();
	Timeline.Reset();
	Details.Reset();
}

void FHitBoxToolEditor::InitHitBoxToolEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UHitBoxToolManager* InObject)
{
	InObject->SetFlags(RF_Transactional);

	Viewport = SNew(SHitBoxToolViewport)
		.HitBoxToolEditor(SharedThis(this))
		.ObjectToEdit(InObject);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	DetailsViewArgs.bHideSelectionTip = true;
	DetailsViewArgs.bShowModifiedPropertiesOption = false;
	DetailsViewArgs.bShowCustomFilterOption = true;

	Details = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	Details->RegisterInstancedCustomPropertyLayout(InObject->StaticClass(), FOnGetDetailCustomizationInstance::CreateStatic(&FHitBoxToolDetails::MakeInstance, InObject));

	Timeline = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	PropertyEditorModule.NotifyCustomizationModuleChanged();

	const TSharedRef<FTabManager::FLayout> EditorDefaultLayout = FTabManager::NewLayout("Standalone_HitBoxTool_Layout_Test_v4")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)
				->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.9f)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.8f)
						->AddTab(ViewportTabId, ETabState::OpenedTab)
						->SetHideTabWell(true)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.2f)
						->AddTab(TimelineTabId, ETabState::OpenedTab)
					)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab(DetailsTabId, ETabState::OpenedTab)
				)
			)
		);

	const FName ToolkitID(FName("HitBoxToolEditor"));
	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, ToolkitID, EditorDefaultLayout, true, true, InObject);
}

void FHitBoxToolEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_HitBoxToolEditor", "HitBoxTool Editor"));
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
	
	InTabManager->RegisterTabSpawner(ViewportTabId, FOnSpawnTab::CreateSP(this, &FHitBoxToolEditor::SpawnTab_Viewport))
		.SetDisplayName(LOCTEXT("ViewportTab", "Viewport"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());

	InTabManager->RegisterTabSpawner(TimelineTabId, FOnSpawnTab::CreateSP(this, &FHitBoxToolEditor::SpawnTab_Timeline))
		.SetDisplayName(LOCTEXT("TimelineTab", "Timeline"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());

	InTabManager->RegisterTabSpawner(DetailsTabId, FOnSpawnTab::CreateSP(this, &FHitBoxToolEditor::SpawnTab_Details))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FHitBoxToolEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(ViewportTabId);
	InTabManager->UnregisterTabSpawner(TimelineTabId);
	InTabManager->UnregisterTabSpawner(DetailsTabId);
}

FName FHitBoxToolEditor::GetToolkitFName() const
{
	return FName("HitBoxToolEditor");
}

FText FHitBoxToolEditor::GetBaseToolkitName() const
{
	return FText::FromString("HitBoxTool Editor");
}

FString FHitBoxToolEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("HitBoxToolEditor");
}

FLinearColor FHitBoxToolEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

TSharedRef<SDockTab> FHitBoxToolEditor::SpawnTab_Viewport(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId().TabType == ViewportTabId);

	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.Label(LOCTEXT("ViewportTabTitle", "Viewport"))
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				Viewport.ToSharedRef()
			]
		];
	return SpawnedTab;
}

TSharedRef<SDockTab> FHitBoxToolEditor::SpawnTab_Timeline(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId().TabType == TimelineTabId);

	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.Label(LOCTEXT("TimelineTabTitle", "Timeline"))
		.OnCanCloseTab_Lambda([]() { return false; })
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				Timeline.ToSharedRef()
			]
		];
	return SpawnedTab;
}

TSharedRef<SDockTab> FHitBoxToolEditor::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId().TabType == DetailsTabId);

	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.Label(LOCTEXT("DetailsTabTitle", "Details"))
		.OnCanCloseTab_Lambda([]() { return false; })
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				Details.ToSharedRef()
			]
		];
	return SpawnedTab;
}

#undef LOCTEXT_NAMESPACE