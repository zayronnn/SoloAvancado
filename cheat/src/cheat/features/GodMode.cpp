#include "GodMode.h"
#include "events.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "limits.h"
#include <random> // Para gerar números aleatórios

namespace Cheat::Features
{
    GodMode::GodMode()
    {
        HookManager::install(app::GHINOEFFMPN_EKHGIHBHEPL, GHINOEFFMPN_EKHGIHBHEPL_Hook);
    }

    int32_t GodMode::GHINOEFFMPN_EKHGIHBHEPL_Hook(app::SkillIdentity* skillIdentity, void* FKJDKGJBGOD, app::TargetHitData* targetHitData, MethodInfo* method)
    {
        auto& vars = Vars::GetInstance();

        // Gerador de números aleatórios entre 1 e 5
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> distrib(1, 5);

        if (skillIdentity->fields.entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY || 
            skillIdentity->fields.entity->fields.AJEHLIOMMJN == app::ECharacterType__Enum::Monster)
        {
            if (vars.Jerav.value())
            {
                // Gera dano aleatório entre 1 e 5
                int randomDamage = distrib(gen);
                
                // Mantém todas as outras configurações originais
                skillIdentity->fields.SkillRange = -1.0f;
                skillIdentity->fields.SkillMinRange = -1.0f;
                targetHitData->fields._reaction = app::eReactionType__Enum::None;
                
                // Apenas modifica o dano para valor entre 1-5
                targetHitData->fields.damageRatio = static_cast<float>(randomDamage);
                targetHitData->fields.damageRatioTotalValue = static_cast<float>(randomDamage);
            }
        }

        return CALL_ORIGIN(GHINOEFFMPN_EKHGIHBHEPL_Hook, skillIdentity, FKJDKGJBGOD, targetHitData, method);
    }
}