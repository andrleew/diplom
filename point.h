#pragma once

#include "utilis.h"

#include <cmath>

namespace NAlgo {
    class TPoint {
    public:
        TPoint(){}

    public:
    double Distance(const TPoint& p);

    inline const double& GetX() { return X; }
    inline const double& GetY() { return Y; }
    inline double& GetX() { return std::static_cast<double&>(GetX()); }
    inline double& GetY() { return std::static_cast<double&>(GetY()); }

    public:
    TPoint& operator=(const TPoint& p) {
        X = p.X;
        Y = p.Y;
        return *this;
    }

    private:
        double X, Y;
    };
} // namespace NAlgo
