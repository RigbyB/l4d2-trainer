#pragma once

#include "../vmt.h"

class ISurface
{
public:
    void DrawSetColor(int r, int g, int b, int a)
    {
        using func = void(__thiscall*)(void*, int, int, int, int);
        reinterpret_cast<func>(get_vfunc(this, 11))(this, r, g, b, a);
    }

    void DrawFilledRect(int x1, int y1, int x2, int y2)
    {
        using func = void(__thiscall*)(void*, int, int, int, int);
        reinterpret_cast<func>(get_vfunc(this, 12))(this, x1, y1, x2, y2);
    }
};
