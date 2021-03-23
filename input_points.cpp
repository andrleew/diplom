#include "input_points.h"

#include <fstream>
#include <cassert>

using namespace NAlgo;

void TInputPoints::Read(const std::string& filePath) {
    std::ifstream in(filePath);
    assert((in.is_open(), string("can't open file ") + filePath))

    TPoint point;
    while (in >> point.GetX() >> point.GetY())
        Points.push_back(point);
    in.close();
}