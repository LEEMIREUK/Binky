#include "HitBoxToolViewportClient.h"
#include "HitBoxToolViewport.h"
#include "HitBoxToolManager.h"

#include "IPersonaPreviewScene.h"
#include "AdvancedPreviewScene.h"

FHitBoxToolViewportClient::FHitBoxToolViewportClient(const TSharedRef<class FAdvancedPreviewScene>& InPreviewScene, const TSharedRef<class SHitBoxToolViewport>& InHitBoxToolViewport, const TWeakPtr<class FHitBoxToolEditor> InHitBoxToolEditor, class UHitBoxToolManager* InObjectToEdit)
	: FEditorViewportClient(nullptr, &InPreviewScene.Get(), StaticCastSharedRef<SHitBoxToolViewport>(InHitBoxToolViewport))
	, HitBoxToolEditor(InHitBoxToolEditor)
{
}

FHitBoxToolViewportClient::~FHitBoxToolViewportClient()
{
}

void FHitBoxToolViewportClient::Initialize()
{
}

void FHitBoxToolViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);
}

void FHitBoxToolViewportClient::Draw(FViewport* InViewport, FCanvas* InCanvas)
{
	FEditorViewportClient::Draw(InViewport, InCanvas);
}

bool FHitBoxToolViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	bool bHandled = false;

	FAdvancedPreviewScene* AdvancedScene = static_cast<FAdvancedPreviewScene*>(PreviewScene);
	bHandled |= AdvancedScene->HandleInputKey(EventArgs);

	return (bHandled) ? true : FEditorViewportClient::InputKey(EventArgs);
}

bool FHitBoxToolViewportClient::InputAxis(FViewport* InViewport, FInputDeviceId DeviceId, FKey Key, float Delta, float DeltaTime, int32 NumSamples /*=1*/, bool bGamepad /*= false*/)
{
	bool bResult = true;

	if (!bDisableInput)
	{
		FAdvancedPreviewScene* AdvancedScene = (FAdvancedPreviewScene*)PreviewScene;
		bResult = AdvancedScene->HandleViewportInput(InViewport, DeviceId, Key, Delta, DeltaTime, NumSamples, bGamepad);
		if (bResult)
		{
			Invalidate();
		}
		else
		{
			bResult = FEditorViewportClient::InputAxis(InViewport, DeviceId, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
	}

	return bResult;
}
