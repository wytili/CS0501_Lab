#include <iostream>
#include "sort.h"
using namespace std;
//快速排序算法quicksort的时间复杂度为 O(NlogN)，而遍历过程进行了 O(N)循环，总的时间复杂度为 O(NlogN)
int main() 
{
    int size;    
    cin >> size;
    int array[size];
    int target;

    for (int i = 0; i < size; i++) 
    {
        cin >> array[i];
    }

    cin >> target;

    quicksort(array, 0 ,size - 1);

    //定义前后两个指针
    int left = 0;
    int right = size - 1;

    // 循环遍历数组
    while (left < right) 
    {
        int sum = array[right] + array[left];
        if (sum == target) 
        {
            cout << array[right] << " " << array[left] << endl;
            return 0;
        }
        else if (sum > target) 
        {
            right--;
        }
        else 
        {
            left++;
        }
    }
    //找不到
    cout << "null" << endl;
}
