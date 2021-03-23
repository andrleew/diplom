#pragma once

#include "iworld.h"

namespace NAlgo
{
    class IMutation {
    public:
        virtual void Do(IWorld&& w) = 0;
        virtual void Undo() = 0;
    private:

    };
} // namespace NAlgo
