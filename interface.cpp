#include "interface.h"

#include <Windows.h>
#include <stdexcept>

CreateInterface get_interface_factory(const std::string& module_name)
{
    const auto handle = GetModuleHandleA(module_name.c_str());

    if (!handle)
    {
        throw std::runtime_error("Couldn't find module \"" + module_name + "\"");
    }

    const auto factory = reinterpret_cast<CreateInterface>(GetProcAddress(handle, "CreateInterface"));

    if (!factory)
    {
        throw std::runtime_error("Couldn't get CreateInterface from module \"" + module_name + "\"");
    }

    return factory;
}

void* get_interface(const CreateInterface factory, const std::string& interface_name)
{
    const auto inter = factory(interface_name.c_str(), nullptr);

    if (!inter)
    {
        throw std::runtime_error("Couldn't get interface \"" + interface_name + "\"");
    }

    return inter;
}
