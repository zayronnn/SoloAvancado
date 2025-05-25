#include "main.h"
#include <Utils.h>
#include "ConfigManager.hpp"
#include "appdata/helpers.h"
#include "appdata/il2cpp-init.h"
#include "cheat/cheat.h"
#include "Render/Renderer.h"

void Run(HMODULE hModule)
{
    il2cppi_new_console();
    
    while (!GetModuleHandleA(xorstr("GameAssembly.dll")) && !FindWindowA(xorstr("UnityWndClass"), nullptr))
    {
        LOG(xorstr("[SoloLevelling] game not found, waiting 2 seconds..."));
        Sleep(2000);
    }

    Utils::SetCurrentPath(Utils::GetModulePath(hModule));
    
    Init(Renderer::DXVersion::D3D11);
    init_il2cpp();

    LOG(xorstr("AO ENTRAR NA PARTE JOGAVEL, AGUARDE 10 MINUTOS, NAO ATIVE AINDA O PRODUTO,"));
	LOG(xorstr("APOS 10 MINUTOS, VOCE PODE ATIVAR O PRODUTO, TECLA DE ATIVACAO > F2."));

    // Aguarda o jogador apertar F2
    while (!(GetAsyncKeyState(VK_F2) & 1))
    {
        Sleep(100);
    }
	
    LOG(xorstr(" F2 pressionado, Produto Ativo e Liberado para usar..."));

    init_cheat();

    // Se quiser, pode manter outro loop para descarregar com END
    while (true)
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            LOG("Encerrando cheat...");
            break;
        }
        Sleep(100);
    }

    FreeLibraryAndExitThread(hModule, 0);
}
