#include "../render/overlay/overlay.h"
#include "../sdk/imgui/imgui.h"
#include "../globals.h"
#include "cheats.h"
#include <iostream>
#include "Windows.h"

void overlay::draw_gui()
{
    ImGui::SetNextWindowSize(ImVec2(600, 400));

    ImGui::Begin("astrax external", nullptr, ImGuiWindowFlags_NoDecoration);
    {
        // Tab selection buttons
        if (ImGui::Button("Visuals")) {
            tab = 0;
        }
        ImGui::SameLine();
        if (ImGui::Button("Misc")) {
            tab = 1;
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        // Tab Content
        if (tab == 0) {
            ImGui::Text("Visuals Settings");
        }
        else if (tab == 1) {
            ImGui::Text("Misc Settings");
        }
    }
    ImGui::End();
}


void Cheats::Run()
{
    while (true) {
        //if (globals::antiflash == true) {
        //    antiflashFunction();
        //}
    }
}