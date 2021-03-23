#pragma once

#include "iworld.h"
#include "point.h"
#include "iinput_data.h"
#include <vector>

namespace NAlgo {
    class TPointWorld : public IWorld{
    public:
        TPointWorld(){}

        void Build(const IINputData&& id, ...);

    private:
        struct TConnectedPoint {
            TPoint point;
            size_t id;
        };

    private:
        std::vector<TConnectedPoint> points;
    };
    
} // namespace NAlgo
