#pragma once

namespace SDK::Structs::Mono
{
    template <typename T>
    struct Array
    {
        void* klass;
        void* monitor;

        void* bounds;
        int length;
        void* vector[1];

        int getLength() {
            return length;
        }

        T getPointer() {
            return (T)vector;
        }
    };
}