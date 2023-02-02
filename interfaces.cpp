#include "interfaces.h"

#include "interface.h"

IEngineVGui* engine_vgui_interface;
ISurface* surface_interface;

void interfaces::populate_interfaces()
{
    const auto engine_factory = get_interface_factory("engine.dll");
    const auto vgui_factory = get_interface_factory("vguimatsurface.dll");

    engine_vgui_interface = static_cast<IEngineVGui*>(get_interface(engine_factory, "VEngineVGui001"));
    surface_interface = static_cast<ISurface*>(get_interface(vgui_factory, "VGUI_Surface031"));
}
