#include <iostream>
#include "stone.h"

using namespace std;

void priorityQueue::percolateDown(int hole)
{
    int child;
    int tmp = arr[hole];
    for(; hole * 2 <= currentsize; hole = child)
    {
        child = hole * 2;
        if(child != currentsize && arr[child + 1] < arr[child]) child++;
        if(arr[child] < tmp) arr[hole] = arr[child];
        else break;
    }
    arr[hole] = tmp;
}

void priorityQueue::buildHeap()
{
    for(int i = currentsize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

priorityQueue::priorityQueue(int capacity)
{
    arr = new int[capacity + 1];
    currentsize = 0;
}

int priorityQueue::deQueue()
{
    int min = arr[1];
    arr[1] = arr[currentsize--];
    percolateDown(1);
    return min;
}

void priorityQueue::enQueue(int &x)
{
    int hole = ++currentsize;
    for(; hole > 1 && x < arr[hole / 2]; hole /= 2)
    {
        arr[hole] = arr[hole / 2];
    }
    arr[hole] = x;
}

priorityQueue::~priorityQueue()
{
    delete [] arr;
}

