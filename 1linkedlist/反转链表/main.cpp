#include <iostream>
#include <vector>
#include "link.h"

using namespace std;

int main()
{
    int k;
    int number;
    vector <int> array;

    while(1)
    {
        cin >> number;
        array.push_back(number);
        if(cin.get() == '\n'){break;}
    }
        
    cin >> k;
    int len = array.size();//length of dynamic int array 
    if( (k < 0) || (k > len) ){cout << "wrong input"; return -1;} //whether k is reasonable

    link dlist; //create double linked list
    for(int i = 0; i < len; i++)//assign values to list
    {
        dlist.insert(i, array[i]);
    }

    int set = len / k;//number of groups to reverse
    for(int i = 0; i < set; i++)
    {
        dlist.BackwardTraverse((i + 1) * k - 1, i * k);
    }

    dlist.ForwardTraverse(k * set, len - 1); //the rest of the numbers

}