#include <iostream>
#include "link.h"

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    link clist(n);
    // clist.traverse();
    while(clist.CurrentLength != 0)
    {clist.remove(k);}
}