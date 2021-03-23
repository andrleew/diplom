#pragma once

#include <vector>

#include "point.h"
#include "iinput_data.h"

namespace NAlgo {
    class TInputPoints : public IINputData {
    public:
        virtual void* Get() {
            return &Points;
        }

        virtual void Read(const std::string& filePath); 
    private:
        std::vector<TPoint> Points;
    };
} // namespace NAlgo
