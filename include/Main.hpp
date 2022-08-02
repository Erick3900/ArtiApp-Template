//
// Created by Alcachofa
//

#pragma once

#include <app.hpp>

using namespace arti;

class Application : public arti::app {

public:
    bool onInit() override;
    bool onUpdate(float delta) override;
};