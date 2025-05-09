#include "NoCooldown.h"
#include "HookManager.h"

namespace Cheat::Features
{
	NoCooldown::NoCooldown()
	{
		HookManager::install(app::KAAIFMKPKAG_IOFMGMJCCFO, KAAIFMKPKAG_IOFMGMJCCFO_Hook);
	}

	void* NoCooldown::KAAIFMKPKAG_IOFMGMJCCFO_Hook(app::KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();

		if (__this->fields.KCBLLGODKIE != nullptr)
		{
			auto entity = __this->fields.KCBLLGODKIE;
			if (entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER)
			{
				if (vars.Novidade.value())
				{
					__this->fields.HPHOOEPCBOJ = 0.5;
					__this->fields.JCJJDJGOBJL = 0;
				}
			}
		}

		return CALL_ORIGIN(KAAIFMKPKAG_IOFMGMJCCFO_Hook, __this, DEJNILEHENL, method);
	}
}
