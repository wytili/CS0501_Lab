#include <iostream>
#include "minHeap.h"
//解题思路：建堆之后把根结点与指定元素min相比较，若小于x则deQueue根结点，循环该步骤直到找到最小的大于指定数字的根结点结束，若没有则输出not exist。由于deQueue操作会改变原队列顺序，故构造一个一样的队列que2用于输出。
using namespace std;
int main()
{
    int capacity, num, min;
    cin >> capacity;
    priorityQueue que(capacity);
    priorityQueue que2(capacity);
    for(int i = 1;i <= capacity; i++)
    {
        cin >> num;
        que.arr[i] = num;
        que2.arr[i] = num;
    }
    que.buildHeap();
    que2.buildHeap();
    cin >> min;
    while(1)
    {
        if(que.currentsize == 0)
        {
            cout << "not exist" << endl;
            for(int i = 1; i <= que2.currentsize; i++)
            {
                cout << que2.arr[i] << " ";
            }
            break;
        }
        if(que.arr[1] < min)
        {       
            que.deQueue();continue;
        }        
        if(que.arr[1] >= min)
        {
            for(int i = 1; i <= que2.currentsize; i++)
            {
                if(que2.arr[i] == que.arr[1])
                {
                    for(int j = i; j <= que2.currentsize; j++)
                    {
                        cout << que2.arr[j] << " ";
                    }
                    break;    
                }
            }
            break;
        }
    }
}