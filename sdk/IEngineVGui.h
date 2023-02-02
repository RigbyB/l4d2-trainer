#pragma once

class IEngineVGui;

enum PaintMode_t
{
    PAINT_UIPANELS = (1 << 0),
    PAINT_INGAMEPANELS = (1 << 1),
    PAINT_CURSOR = (1 << 2)
};
