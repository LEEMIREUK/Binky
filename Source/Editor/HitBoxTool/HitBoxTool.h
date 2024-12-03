#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class HITBOXTOOL_API FHitBoxTool : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterHitBoxToolMenu();
	void OnClickHitBoxToolMenu();
	void OnClickHitBoxTool();
};