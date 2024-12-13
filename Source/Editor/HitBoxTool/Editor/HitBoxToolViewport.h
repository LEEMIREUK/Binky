#pragma once

#include "CoreMinimal.h"
#include "SEditorViewport.h"

class HITBOXTOOL_API SHitBoxToolViewport : public SEditorViewport
{
public:
	SLATE_BEGIN_ARGS(SHitBoxToolViewport) {}
		SLATE_ARGUMENT(TWeakPtr<class FHitBoxToolEditor>, HitBoxToolEditor)
		SLATE_ARGUMENT(class UHitBoxToolManager*, ObjectToEdit)
	SLATE_END_ARGS()

protected:
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;

public:
	SHitBoxToolViewport();
	~SHitBoxToolViewport();
	void Construct(const FArguments& InArgs);

private:
	TWeakPtr<class FHitBoxToolEditor> HitBoxToolEditor;

	TSharedPtr<class FAdvancedPreviewScene> PreviewScene;

	TSharedPtr<class FHitBoxToolViewportClient> HitBoxToolViewportClient;

	class UHitBoxToolManager* HitBoxToolManager;
};
