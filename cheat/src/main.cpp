﻿#include "main.h"
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
        LOG(xorstr("[SoloLevelling] game not found, waiting 3 seconds..."));
        Sleep(3000);
    }

    Utils::SetCurrentPath(Utils::GetModulePath(hModule));
    
    Init(Renderer::DXVersion::D3D11);
    init_il2cpp();

    LOG(xorstr("[SoloLevelling] Cheat aguardando F2 no lobby para iniciar..."));

    // Aguarda o jogador apertar F2
    while (!(GetAsyncKeyState(VK_F2) & 1))
    {
        Sleep(100);
    }

    LOG(xorstr("[SoloLevelling] F2 pressionado — inicializando cheat..."));

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
