#include <iostream>
using namespace std;

#include "point.h"

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cin >> x4 >> y4 >> x5 >> y5; 
    Point p1(x1, y1);
    Point p2(x2, y2);
    Point p3(x3, y3);
    Triangle tri(p1, p2, p3);
    Circle cir(x4, y4, x5, y5);
    cout << tri.girth() << " " << tri.area() << endl;
    cout << cir.girth() << " " << cir.area();
}