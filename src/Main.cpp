//
// Created by Alcachofa
//
#include <Main.hpp>

#include <imgui.hpp>
#include <IconsFontAwesome5.h>
#include <constants/colors.hpp>

bool Application::onInit() {
    this->setIcon("assets/appIcon.png");

    auto &io = ImGui::GetIO();

    io.IniFilename = nullptr;

    ImFontConfig config;
    config.SizePixels = 32.0f;
    config.OversampleH = 3;
    config.OversampleV = 3;

    io.Fonts->AddFontFromFileTTF("assets/CaskaydiaCoveNF-Mono-Light.otf", 32.0f, &config);

    config.MergeMode = true;

    static const ImWchar icon_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};

    io.Fonts->AddFontFromFileTTF("assets/fa-regular-400.ttf", 32.0f, &config, icon_ranges);
    io.Fonts->AddFontFromFileTTF("assets/fa-brands-400.ttf", 32.0f, &config, icon_ranges);
    io.Fonts->AddFontFromFileTTF("assets/fa-solid-900.ttf", 32.0f, &config, icon_ranges);

    io.Fonts->Build();

    if (!ImGui::SFML::UpdateFontTexture())
    {
        return false;
    }

    io.FontGlobalScale = 0.5;

    return true;
}

bool Application::onUpdate(float delta) {
    graphics->clear(colors::OffBlack);

    ImGui::ShowDemoWindow();

    return true;
}
