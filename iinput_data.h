#pragma once

#include <string>

namespace NAlgo {
    class IINputData {
    public:
        virtual void* Get() = 0;
        virtual void Read(const std::string&& filePath);
    };
}