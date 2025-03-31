#include "cheat.h"
#include "global.h"
#include "HookManager.h"
#include "events.h"
#include "HotkeyManager.hpp"

#include "features/NoCooldown.h"
#include "features/DamageHack.h"
#include "features/GodMode.h"
#include "features/DumbEnemies.h"
#include "features/FovChanger.h"
#include "features/FPSUnlock.h"
#include "features/TimeScale.h"
#include "features/Debug.h"
#include "features/EntityManager.h"

using namespace Cheat::Features;

static void GameFrameWork_Update_Hook(void* __this, MethodInfo* method);

void init_cheat()
{
#define INIT_FEATURE(feature) feature::GetInstance()
	INIT_FEATURE(NoCooldown);
	INIT_FEATURE(DamageHack);
	INIT_FEATURE(GodMode);
	INIT_FEATURE(DumbEnemies);
	INIT_FEATURE(TimeScale);
	INIT_FEATURE(FPSUnlock);
	INIT_FEATURE(FovChanger);
	INIT_FEATURE(Debug);
	//INIT_FEATURE(EntityManager);
#undef INIT_FEATURE

	HookManager::install(app::GameFrameWork_Update, GameFrameWork_Update_Hook);
}

void GameFrameWork_Update_Hook(void* __this, MethodInfo* method)
{
	SAFE_BEGIN();
	events::GameUpdateEvent();
	HotkeyManager::GetInstance().CheckForKeyPress();
	SAFE_EEND();
	CALL_ORIGIN(GameFrameWork_Update_Hook, __this, method);
}