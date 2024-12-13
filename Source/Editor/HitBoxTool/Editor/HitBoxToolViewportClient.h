#pragma once

#include "CoreMinimal.h"
#include "EditorViewportClient.h"

class HITBOXTOOL_API FHitBoxToolViewportClient : public FEditorViewportClient
{
public:
	FHitBoxToolViewportClient(
		const TSharedRef<class FAdvancedPreviewScene>& InPreviewScene,
		const TSharedRef<class SHitBoxToolViewport>& InHitBoxToolViewport,
		const TWeakPtr<class FHitBoxToolEditor> InHitBoxToolEditor,
		class UHitBoxToolManager* InObjectToEdit);
	~FHitBoxToolViewportClient();

	void Initialize();

protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void Draw(FViewport* InViewport,FCanvas* InCanvas) override;
	virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;
	virtual bool InputAxis(FViewport* InViewport, FInputDeviceId DeviceId, FKey Key, float Delta, float DeltaTime, int32 NumSamples =1, bool bGamepad = false) override;

public:
	TSharedRef<class FHitBoxToolEditor> GetHitBoxToolEditor() const { return HitBoxToolEditor.Pin().ToSharedRef(); }

private:
	TWeakPtr<class FHitBoxToolEditor> HitBoxToolEditor;
};
