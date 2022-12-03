#include <iostream>
using namespace std;

#ifndef _STONE_H
#define _STONE_H

class priorityQueue
{
    public:
        long currentsize;
        int *arr;
        void percolateDown(int hole);
        void buildHeap();
        int deQueue();
        void enQueue(int &x);
        priorityQueue(int capacity);
        ~priorityQueue();
};

#endif