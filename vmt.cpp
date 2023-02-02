#include "vmt.h"

#include <cstring>
#include <stdexcept>
#include <string>

void vmt_hook::init(void* class_)
{
    original_table_ = get_vtable(class_);

    num_functions_ = 0;
    while (original_table_[num_functions_])
        num_functions_ += 1;

    new_table_ = new void*[num_functions_];
    memcpy(new_table_, original_table_, sizeof(void*) * num_functions_);

    override_vtable(class_, new_table_);

    initialised_ = true;
}

void* vmt_hook::hook_function(const size_t index, void* hook_function) const
{
    if (!initialised_)
        return nullptr;

    if (index > num_functions_)
    {
        throw std::runtime_error(
            "Index " + std::to_string(index) + " is greater than the number of functions for this virtual table");
    }

    new_table_[index] = hook_function;

    return original_table_[index];
}

void vmt_hook::unhook_function(const size_t index) const
{
    hook_function(index, original_table_[index]);
}

void vmt_hook::unhook_all_functions() const
{
    for (size_t i = 0; i < num_functions_; i++)
    {
        unhook_function(i);
    }
}

void** get_vtable(void* class_)
{
    return *static_cast<void***>(class_);
}

void override_vtable(void* class_, void** new_table)
{
    *static_cast<void***>(class_) = new_table;
}

void* get_vfunc(void* class_, const int index)
{
    return get_vtable(class_)[index];
}
