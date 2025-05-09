#include "gui.h"
#include "global.h"
#include "imgui.h"
#include "Utils.h"
#include "utils/gui-util.hpp"

void Gui::Render()
{
	auto& vars = Vars::GetInstance();
	
    ImGui::Begin(xorstr("##Taiga74164"), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::BeginGroup();
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
    GuiUtil::CenterText(xorstr("Mindware l discord.gg/xyFuZw7gdz l License: 01/01 l HWID: **********"), 0, 0);
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::PopStyleColor();
}
ImGui::EndGroup();

// Comente ou remova esta linha para eliminar o efeito de cor
// GuiUtil::RainbowLine();

ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
ImGui::BeginChild(xorstr("##LeftSide"), ImVec2(100, GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

#define MENU_MODULES(name, tab) ImGui::PushStyleColor(ImGuiCol_Button, m_MenuTab == (tab) ? active : inactive); \
		     ImGui::Button(name, ImVec2(90 - 10, 22)); \
		     if (ImGui::IsItemClicked()) m_MenuTab = tab; \
		     ImGui::PopStyleColor()

			MENU_MODULES(xorstr("Recursos"), 0);
			MENU_MODULES(xorstr("Outros"), 1);
			MENU_MODULES(xorstr("Teclas"), 2);
			MENU_MODULES(xorstr("Sobre"), 3);

#undef MENU_MODULES
		}
		ImGui::EndChild();

		GuiUtil::LineVertical();

		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild(xorstr("##RightSide"), ImVec2(GuiUtil::GetX(), GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImGuiCol_Button ? active : inactive);
		switch (m_MenuTab)
		{
		case 0: // Features
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill(xorstr("Regenera Instantaneo MP"), &vars.Blong.value()); HELPMAKER(xorstr("Pressione Espaco"));
			ImGui::CheckboxFill(xorstr("Regenera Instantaneo HP"), &vars.Blongg.value()); HELPMAKER(xorstr("Pressione Espaco"));

			ImGui::CheckboxFill(xorstr("Skill Infinita"), &vars.Novidade.value()); HELPMAKER(xorstr("Caso use em conjunto com o Dano Hack, analise o Dano do F e o dano padrao, se estiver alto ajuste o dano hack"));
			
			ImGui::CheckboxFill(xorstr("Skill Infinita Sombras (Risco nao determinado)"), &vars.SemNovidade.value()); HELPMAKER(xorstr("Habilite somente se você tiver o recurso de sombra disponível"));
			
			ImGui::CheckboxFill(xorstr("Inimigos Burros"), &vars.Burro.value()); HELPMAKER(xorstr("Isso evitara que os inimigos ataquem ou se movam em sua direcao, recomendo levar dano."));

			ImGui::CheckboxFill(xorstr("Dano Hack (Risco de Aviso)"), &vars.Miconho.value()); HELPMAKER(xorstr("Recomendo colocar valores que voce precisa passar a fase, nao abuse"));
			if (vars.Miconho.value())
				ImGui::SliderInt(xorstr("Valor"), &vars.MiconhoNovoValue.value(), 100, 70000, "%d");
			
			ImGui::TextColored(ImVec4(0.4f, 0.9098f, 0.5412f, 1.0f), xorstr("(Coloque apenas valores legit, para passar a fase)")); // Texto vermelho
			
				
			 ImGui::Spacing();
			 ImGui::Spacing();
			 ImGui::Spacing();
			 ImGui::Spacing();
			 
			ImGui::CheckboxFill(xorstr("Modo Deus (Risco baixo)"), &vars.Jerav.value()); HELPMAKER(xorstr("Nao recomendo o uso, e bom sempre tomar dano, voce leva dano entre 1 a 5 para enviar dados pro servidor."));

			ImGui::CheckboxFill(xorstr("Kill Aura (Risco Alto de Ban)"), &vars.Blade.value()); HELPMAKER(xorstr("O dano e absurdo, cuidado!"));
						ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			
			ImGui::TextColored(ImVec4(0.4f, 0.9098f, 0.5412f, 1.0f), xorstr("(Recomendamos o uso em uma conta ALT)")); // Texto vermelho
			ImGui::TextColored(ImVec4(0.4f, 0.9098f, 0.5412f, 1.0f), xorstr("(Nao use o produto no capitulo 12, missao final)")); // Texto vermelho

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 1: // Misc
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill(xorstr("Mudar Fov"), &vars.Globo.value());
			if (vars.Globo.value())
				ImGui::SliderFloat(xorstr("Fov"), &vars.Fov.value(), 1.0f, 360.0f, "%.1f");


			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 2: // Hotkeys
			ImGui::InputHotkey(xorstr("Regenera Instantaneo MP"), vars.Blong);
			ImGui::InputHotkey(xorstr("Regenera Instantaneo HP"), vars.Blongg);
			ImGui::InputHotkey(xorstr("Skilll Infinita"), vars.Novidade);
			ImGui::InputHotkey(xorstr("Skilll Infinita Sombras"), vars.SemNovidade);
			ImGui::InputHotkey(xorstr("Modo Deus"), vars.Jerav);
			ImGui::InputHotkey(xorstr("Dano Hack"), vars.Miconho);
			ImGui::InputHotkey(xorstr("Kill Aura"), vars.Blade);
			ImGui::InputHotkey(xorstr("Inimigos Burros"), vars.Burro);
			ImGui::InputHotkey(xorstr("Mudar FOV"), vars.Globo);

			break;
		case 3: // About
			ImGui::Spacing();
			ImGui::Text(xorstr("Mindware - License:01/01 l HWID:*****************"));
			ImGui::Text(xorstr("Created by: Mindware"));
			ImGui::Text(xorstr("We do not have any resellers or partnerships"));
			ImGui::Text(xorstr("Nao temos nenhum Revendedor ou Parceria"));
			ImGui::TextURL(xorstr("Discord"), xorstr("https://discord.gg/xyFuZw7gdz"));
			
			
			break;
		}

		ImGui::PopStyleColor();
		ImGui::EndChild();
    }

    ImGui::End();
}