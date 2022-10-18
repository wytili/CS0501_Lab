#include <iostream>
#include <math.h>
using namespace std;

#include "point.h"

double Triangle :: girth() const
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) + sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y)) + sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
}

double Triangle :: area() const
{
    double a, b, c;
    a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    b = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
    c = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
    double p = (a + b + c)/2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Circle :: girth() const
{
    double r;
    r = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    return 2 * 3.14 * r;
}
double Circle :: area() const
{
    double r;
    r = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    return 3.14 * r * r;
}