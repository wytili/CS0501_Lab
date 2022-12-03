#include <iostream>
#include "stone.h"
//����˼·������С���Ѵ洢n��ʯ�ӣ�deQueueǰ�����εĸ���㼴Ϊ��С������ʯ�ӣ������Ǻϲ�֮���ʯ��enQueue�����У�ѭ���˲�ֱ��ֻʣ��һ��ʯͷΪֹ�������ʼֵΪ0�����ͱ���HP��¼���ĵ��������ڽ���ÿ�κϲ�ʱ��������ʯ��֮�͡�
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
