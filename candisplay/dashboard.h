// parser.h
#pragma once

#include <imgui.h>
#include "model.h"

class Dashboard
{
public:
    // Renders the dashboard using the provided model data.
    static void render(Model& model);
};