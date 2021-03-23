#pragma once

#include "iinput_data.h"
#include <vector>

namespace NAlgo
{
    class IWorld {
    public:
        virtual void Build(const IINputData&& args, ...) = 0;

        virtual double GetScore() = 0;
    protected:
    };
} // namespace NAlgo
