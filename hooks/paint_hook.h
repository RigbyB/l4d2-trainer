#pragma once

using Paint = void(__thiscall*)(void*, int);

void __fastcall paint_hook(void* ecx, void*, int mode);

extern Paint paint_pointer;
