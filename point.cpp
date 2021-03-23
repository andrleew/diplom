#include "point.h"


double NAlgo::TPoint::Distance(const TPoint& p) {
    return sqrt(Sqr(p.X - X) + Sqr(p.Y - Y));
}