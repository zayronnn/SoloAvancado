#include "DamageHack.h"
#include "events.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include <random>

namespace Cheat::Features
{
    namespace
    {
        // Sistema de valores pré-calculados
        constexpr int64_t DAMAGE_VALUES[] = {1, 2, 3, 4, 5};
        constexpr int64_t MP_RECOVERY_VALUES[] = {500, 550, 600};
        constexpr int64_t HP_RECOVERY_VALUES[] = {650, 700, 750};
        
        // Índices rotativos para valores pseudo-aleatórios
        static size_t damageIndex = 0;
        static size_t mpIndex = 0;
        static size_t hpIndex = 0;
        
        // Gerador de índice simples baseado em tempo
        size_t GetRotatingIndex(size_t& index, size_t max) {
            index = (index + 1) % max;
            return index;
        }
    }

    DamageHack::DamageHack()
    {
        HookManager::install(app::PIPHNBOBFEF_KBCIIEFLPGB, PIPHNBOBFEF_KBCIIEFLPGB_Hook);
    }

    void DamageHack::PIPHNBOBFEF_KBCIIEFLPGB_Hook(app::PIPHNBOBFEF* __this, app::ESpecialState__Enum specialState, 
        int64_t someInt1, int64_t someInt2, int64_t someInt3, app::String* buffName, MethodInfo* method)
    {
        auto& vars = Vars::GetInstance();
        
        // Verificação de segurança original
        if (!__this || !__this->fields.IGFILCLEFHH || !__this->fields.IGFILCLEFHH->fields.EJBODHBGPMG)
            return CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, specialState, someInt1, someInt2, someInt3, buffName, method);

        const auto entity = __this->fields.IGFILCLEFHH->fields.EJBODHBGPMG;
        const bool isPlayer = entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER;
        const bool isEnemy = entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY;

        // Processamento para jogador
        if (isPlayer)
        {
            // Recuperação de MP
            if (vars.Blong.value())
            {
                CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::MpRecovery, 
                    2i64, 
                    MP_RECOVERY_VALUES[GetRotatingIndex(mpIndex, std::size(MP_RECOVERY_VALUES))], 
                    0i64, buffName, method);
            }
            
            // Recuperação de HP
            if (vars.Blongg.value())
            {
                CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::HpRecovery, 
                    2i64, 
                    HP_RECOVERY_VALUES[GetRotatingIndex(hpIndex, std::size(HP_RECOVERY_VALUES))], 
                    0i64, buffName, method);
            }

            // GodMode (dano reduzido 1-5)
            if (vars.Jerav.value() && 
               (specialState == app::ESpecialState__Enum::None || 
                specialState == app::ESpecialState__Enum::DotDamage))
            {
                return CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::FixDamage,
                    DAMAGE_VALUES[GetRotatingIndex(damageIndex, std::size(DAMAGE_VALUES))], 
                    0i64, 0i64, buffName, method);
            }
        }

        // Processamento para inimigos
        if (isEnemy)
        {
            // DamageHack
            if (vars.Miconho.value())
            {
                const int64_t modifiedDamage = vars.MiconhoNovoValue.value() + 
                                             (GetRotatingIndex(damageIndex, 5) * 500); // Variação de dano
                
                return CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::FixDamage,
                    modifiedDamage, 
                    0i64, 0i64, buffName, method);
            }

            // KillAura
            if (vars.Blade.value())
            {
                constexpr int64_t killAuraDamage = 10000; // Valor reduzido para ser menos óbvio
                constexpr int64_t shieldBreak = -5000;
                constexpr int64_t defenseBreak = 2000;
                
                CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::DotDamage, 2i64, killAuraDamage, 0i64, buffName, method);
                CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::Shield, 2i64, shieldBreak, 0i64, buffName, method);
                CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, 
                    app::ESpecialState__Enum::DotBreak, 2i64, defenseBreak, 0i64, buffName, method);
            }
        }

        // Chamada original se nenhum modificador for aplicado
        CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, specialState, someInt1, someInt2, someInt3, buffName, method);
    }
}