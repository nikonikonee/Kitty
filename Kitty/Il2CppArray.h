#pragma once

namespace SDK::Structs::IL2CPP
{
    typedef struct Il2CppArray
    {
        void* klass;
        void* monitor;
        void* bounds;
        size_t max_length;
        void* vector[32];
    } Il2CppArray;
}