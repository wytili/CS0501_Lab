#include <iostream>
#include "minHeap.h"
//����˼·������֮��Ѹ������ָ��Ԫ��min��Ƚϣ���С��x��deQueue����㣬ѭ���ò���ֱ���ҵ���С�Ĵ���ָ�����ֵĸ�����������û�������not exist������deQueue������ı�ԭ����˳�򣬹ʹ���һ��һ���Ķ���que2���������
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