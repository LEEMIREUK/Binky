#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "DetailCategoryBuilder.h"

class HITBOXTOOL_API FHitBoxToolDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance(class UHitBoxToolManager* InManager);
	void SetHitBoxToolManager(class UHitBoxToolManager* InManager);
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	class UHitBoxToolManager* HitBoxToolManager;
};