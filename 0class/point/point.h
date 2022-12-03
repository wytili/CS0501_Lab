#ifndef _point_h
#define _point_h
#include <iostream>
using namespace std;

class Point
{ 
    public:
        double x, y;
        Point(double a = 0, double b = 0){x = a; y = b;}
        ~Point(){};
};

class Triangle
{
    Point p1;
    Point p2;
    Point p3;
    
    public:
        Triangle(Point pt1, Point pt2, Point pt3): p1(pt1), p2(pt2), p3(pt3) {}
        double girth() const;
        double area() const;
        ~Triangle(){};
};

class Circle:public Point
{
    double x2, y2;

    public:
        Circle(double a, double b, double c, double d){x = a, y = b, x2 = c, y2 = d;}
        double girth() const;
        double area() const;
        ~Circle(){};
};

#endif