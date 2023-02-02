#pragma once

#include "sdk/IEngineVGui.h"
#include "sdk/ISurface.h"

class interfaces
{
public:
    static void populate_interfaces();
};

extern IEngineVGui* engine_vgui_interface;
extern ISurface* surface_interface;
