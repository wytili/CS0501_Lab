#include <iostream>
using namespace std;

#ifndef _MINHEAP_H
#define _MINHEAP_H

class priorityQueue
{
    public:
        int currentsize;
        int *arr;
        void percolateDown(int hole);
        void buildHeap();
        int deQueue();
        priorityQueue(int capacity);
        ~priorityQueue();
};

#endif