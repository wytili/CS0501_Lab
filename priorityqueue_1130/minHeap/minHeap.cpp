#include <iostream>
#include "minHeap.h"

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
    currentsize = capacity;
}

int priorityQueue::deQueue()
{
    int min = arr[1];
    arr[1] = arr[currentsize--];
    percolateDown(1);
    return min;
}

priorityQueue::~priorityQueue()
{
    delete [] arr;
}

