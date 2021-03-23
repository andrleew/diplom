#pragma once

#include "imutation.h"
#include "simple_random.h"

#include <vector>
#include <memory>
#include <cassert>

namespace NAlgo {
    class TMutationManager {
    public:
        TMutationManager()
        : Gen(std::make_shared<TSimpleRandom>())
        {}

    template <class _Mutation_>
    TMutationManager& Add(size_t count) {
        Mutations.push_back({
            .Count = count,
            .Mutation = std::make_shared<_Mutation_>()
        });
        Sum += count;
        return *this;
    }

    IMutation& Get() {
        assert((!Mutations.empty(), "There is no mutations"));
        
        auto value = (*Gen)() % Sum;
        for (auto& mutation : Mutations) {
            if (value < mutation.Count) return *mutation.Mutation.get();
            else value -= mutation.Count;
        }
    }

    private:
        struct TMutationElement {
            size_t Count;
            std::shared_ptr<IMutation> Mutation;
        };

    private:
        std::shared_ptr<IRandom<size_t>> Gen;
        std::vector<TMutationElement> Mutations;
        size_t Sum;
    };
} // namespace NAlgo
