#include <iostream>
#include "sort.h"
using namespace std;
//使用快速排序算法，对数组排序后直接找中位数。时间复杂度最好情况下为O(NlogN),最坏情况下O(N^2),平均情况下O(NlogN)
int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        cin.get();
    }
    quicksort(arr, 0, size - 1);
    if(size % 2 == 0)cout << (arr[size / 2] + arr[size / 2 - 1]) / 2;
    else cout << arr[size / 2];
    
}