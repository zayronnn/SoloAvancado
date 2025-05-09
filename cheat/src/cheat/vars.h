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
	CONFIG_ENTRY_HOTKEY(bool, Novidade, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, SemNovidade, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, Jerav, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, Blade, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, Miconho, false, Hotkey());
	CONFIG_ENTRY(int, MiconhoNovoValue, 100);
	CONFIG_ENTRY_HOTKEY(bool, Burro, false, Hotkey());

	// Misc
	CONFIG_ENTRY_HOTKEY(bool, Globo, false, Hotkey());
	CONFIG_ENTRY(float, Fov, 60.0f);
};
