#pragma once

#include <memory>

class vmt_hook
{
public:
    explicit vmt_hook(void* class_);
    ~vmt_hook();
    void* hook_function(size_t index, void* hook_function) const;
    void unhook_function(size_t index) const;
    void unhook_all_functions() const;

private:
    void* class_owner_;
    void** original_table_;
    std::unique_ptr<void*[]> new_table_;
    size_t num_functions_;
};

void** get_vtable(void* class_);
void override_vtable(void* class_, void** new_table);
void* get_vfunc(void* class_, int index);
