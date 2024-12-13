#include "HitBoxToolDetails.h"

TSharedRef<IDetailCustomization> FHitBoxToolDetails::MakeInstance(class UHitBoxToolManager* InManager)
{
	TSharedRef<FHitBoxToolDetails> Instance = MakeShared<FHitBoxToolDetails>();
	Instance->SetHitBoxToolManager(InManager);
	return Instance;
}

void FHitBoxToolDetails::SetHitBoxToolManager(class UHitBoxToolManager* InManager)
{
	HitBoxToolManager = InManager;
}

void FHitBoxToolDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	// Slate
}
