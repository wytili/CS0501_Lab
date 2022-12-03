#include <iostream>
#include "stone.h"
//解题思路：用最小化堆存储n堆石子，deQueue前后两次的根结点即为最小的两堆石子，把它们合并之后的石堆enQueue进队列，循环此步直到只剩下一堆石头为止。定义初始值为0的整型变量HP记录消耗的体力，在进行每次合并时都加上两石堆之和。
using namespace std;
int main()
{
    long capacity;
    int num;
    cin >> capacity;
    priorityQueue que(capacity);
    while(cin >> num)
    {
        que.currentsize++;
        que.arr[que.currentsize] = num;
        if(cin.get() == '\n')break;//change to EOF in educoder
    }

    if(que.currentsize != capacity)
    {
        cout << "error";
        return -1;
    }

    que.buildHeap();

    int HP = 0, lastroot, nextroot;
    for(int i = 0; i < (capacity - 1); i++)
    {
        lastroot = que.deQueue();
        nextroot = que.deQueue();
        int sum = lastroot + nextroot;
        que.enQueue(sum);
        HP += sum;
    }
    cout << HP;
}
