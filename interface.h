#pragma once

#include <string>

using CreateInterface = void*(*)(const char* pName, int* pReturnCode);

CreateInterface get_interface_factory(const std::string& module_name);
void* get_interface(const CreateInterface factory, const std::string& interface_name);
