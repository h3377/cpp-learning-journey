#pragma once

#include <iostream>
using namespace std;

namespace MyGeometryLib
{
    double CircleArea(double radius)
    {
        const double PI = 3.14159;
        return PI * radius * radius;
    }

    double RectangleArea(double length, double width)
    {
        return length * width;
    }

    double TriangleArea(double base, double height)
    {
        return (base * height) / 2.0;
    }

    double BoxVolume(double length, double width, double height)
    {
        return length * width * height;
    }
}
