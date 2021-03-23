#pragma once

#include <cstddef>

namespace NAlgo {
    template <class T>
    class IRandom {
    public:
        virtual T operator()() = 0;
    };
} // namespace NAlg 
