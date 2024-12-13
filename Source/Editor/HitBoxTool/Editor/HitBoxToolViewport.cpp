#include "HitBoxToolViewport.h"
#include "HitBoxToolViewportClient.h"
#include "../../../../../../../Source/Editor/Persona/Private/AnimationEditorPreviewScene.h"


TSharedRef<FEditorViewportClient> SHitBoxToolViewport::MakeEditorViewportClient()
{
	HitBoxToolViewportClient = MakeShareable(new FHitBoxToolViewportClient(PreviewScene.ToSharedRef(), SharedThis(this), HitBoxToolEditor.Pin().ToSharedRef(), HitBoxToolManager));

	HitBoxToolViewportClient->Initialize();

	HitBoxToolViewportClient->ViewportType = LVT_Perspective;
	HitBoxToolViewportClient->bSetListenerPosition = false;
	HitBoxToolViewportClient->SetViewLocation(EditorViewportDefs::DefaultPerspectiveViewLocation);
	HitBoxToolViewportClient->SetViewRotation(EditorViewportDefs::DefaultPerspectiveViewRotation);

	return HitBoxToolViewportClient.ToSharedRef();
}

SHitBoxToolViewport::SHitBoxToolViewport()
	: PreviewScene(MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues())))
{

}

SHitBoxToolViewport::~SHitBoxToolViewport()
{

}

void SHitBoxToolViewport::Construct(const FArguments& InArgs)
{
	HitBoxToolEditor = InArgs._HitBoxToolEditor;
	HitBoxToolManager = InArgs._ObjectToEdit;

	SEditorViewport::Construct(SEditorViewport::FArguments());
}
 