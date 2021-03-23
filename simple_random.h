#pragma once

#include "irandom.h"
#include <random>
#include <ctime>

namespace NAlgo {
    template<class T = size_t>
    class TSimpleRandom : public IRandom<T> {
    public:
        TSimpleRandom()
        {
            Gen.seed(time(0));
        }

        virtual T operator()() {
            return Gen();
        }
    private:
        std::mt19937 Gen;
    };
} // namespace NAlgo
