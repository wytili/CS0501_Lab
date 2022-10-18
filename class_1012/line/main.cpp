#include <iostream>
using namespace std;

#include "line.h"

int main()
{
    double x11, y11, x21, y21, x12, y12, x22, y22;
    char a;
    cin >> x11 >> y11 >> x21 >> y21;
    cin >> x12 >> y12 >> x22 >> y22;
    cin >> a;
    line line1(x11, y11, x21, y21);
    line line2(x12, y12, x22, y22);
    cout << length(line1) << " " << length(line2) << endl;
    if(a == '<')
    {
        if(length(line1) < length(line2))
        {
            cout << "Yes!";
        }
        else cout << "No!"; 
    }

    if(a == '>')
    {
        if(length(line1) > length(line2))
        {
            cout << "Yes!";
        }
        else cout << "No!"; 
    }

    if(a == '=')
    {
        if(length(line1) == length(line2))
        {
            cout << "Yes!";
        }
        else cout << "No!"; 
    }
}