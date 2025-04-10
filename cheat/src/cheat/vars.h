#pragma once

#include "ConfigEntry.hpp"
#include "Hotkey.h"

class Vars final : public Singleton<Vars>
{
public:
	Vars() = default;

	// Features
	CONFIG_ENTRY_HOTKEY(bool, Blong, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, Blongg, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, NoCooldown, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, NoCooldownShadow, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, GodMode, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, KillAura, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, DamageHack, false, Hotkey());
	CONFIG_ENTRY(int, DamageHackValue, 100);
	CONFIG_ENTRY_HOTKEY(bool, DumbEnemies, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, TimeScale, false, Hotkey());
	CONFIG_ENTRY(float, TimeScaleSpeed, 2.0f);

	// Misc
	CONFIG_ENTRY_HOTKEY(bool, FPSUnlock, false, Hotkey());
	CONFIG_ENTRY(int, FPSValue, 240);
	CONFIG_ENTRY_HOTKEY(bool, FovChanger, false, Hotkey());
	CONFIG_ENTRY(float, Fov, 60.0f);
};
