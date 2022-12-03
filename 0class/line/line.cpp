#include <iostream>
#include <math.h>
using namespace std;

#include "line.h"

double length(const line &p)
{
    return sqrt((p.x1 - p.x2) * (p.x1 - p.x2) + (p.y1 - p.y2) * (p.y1 - p.y2));
}

bool operator>(const line &p1, const line &p2)
{
    return length(p1) > length(p2);
}

bool operator<(const line &p1, const line &p2)
{
    return length(p1) < length(p2);
}

bool operator==(const line &p1, const line &p2)
{
    return length(p1) == length(p2);
}