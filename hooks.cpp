#include "hooks.h"

#include "interfaces.h"

#include "hooks/paint_hook.h"

Paint paint_pointer;

std::unique_ptr<vmt_hook> engine_vgui_hook;

void hooks::hook_interfaces()
{
    engine_vgui_hook = std::make_unique<vmt_hook>(engine_vgui_interface);

    paint_pointer = reinterpret_cast<Paint>(engine_vgui_hook->hook_function(14, reinterpret_cast<void*>(paint_hook)));
}
