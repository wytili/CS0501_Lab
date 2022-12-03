#ifndef _line_h
#define _line_h
#include <iostream>
using namespace std;

class line
{
friend double length(const line &p);
friend bool operator>(const line &p1, const line &p2);
friend bool operator<(const line &p1, const line &p2);
friend bool operator==(const line &p1, const line &p2);

private:
        double x1, y1, x2, y2;
public:        
        line(double a=0, double b=0, double c=0, double d=0){x1 = a, y1 = b, x2 = c,y2 = d;}
        
};

#endif