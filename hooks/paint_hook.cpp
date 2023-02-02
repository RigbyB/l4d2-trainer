#include "paint_hook.h"

#include "../interfaces.h"

void __fastcall paint_hook(void* ecx, void*, int mode)
{
    paint_pointer(ecx, mode);

    if (!(mode & PAINT_UIPANELS))
        return;

    surface_interface->DrawSetColor(255, 0, 0, 255);
    surface_interface->DrawFilledRect(20, 20, 50, 50);
}
