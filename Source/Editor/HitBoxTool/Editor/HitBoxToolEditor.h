#pragma once

#include "CoreMinimal.h"
#include "PersonaAssetEditorToolkit.h"

class HITBOXTOOL_API FHitBoxToolEditor : public FPersonaAssetEditorToolkit
{
public:
	FHitBoxToolEditor();
	virtual ~FHitBoxToolEditor();

	void InitHitBoxToolEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UHitBoxToolManager* InObject);

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetDocumentationLink() const override
	{
		return TEXT("NotAvailable");
	}

private:
	TSharedRef<SDockTab> SpawnTab_Viewport(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Timeline(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Details(const FSpawnTabArgs& Args);

private:
	TSharedPtr<class SHitBoxToolViewport> Viewport;
	TSharedPtr<class IDetailsView> Timeline;
	TSharedPtr<class IDetailsView> Details;

private:
	static const FName ViewportTabId;
	static const FName TimelineTabId;
	static const FName DetailsTabId;

private:
	class UHitBoxToolManager* HitBoxToolManager;
};