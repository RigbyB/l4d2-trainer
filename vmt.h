#pragma once

class vmt_hook
{
public:
    void init(void* class_);
    void* hook_function(size_t index, void* hook_function) const;
    void unhook_function(size_t index) const;
    void unhook_all_functions() const;

private:
    void** original_table_ = nullptr;
    void** new_table_ = nullptr;
    size_t num_functions_ = 0;
    bool initialised_ = false;
};

void** get_vtable(void* class_);
void override_vtable(void* class_, void** new_table);
void* get_vfunc(void* class_, int index);
