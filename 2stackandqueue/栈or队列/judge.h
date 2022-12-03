#include <iostream>
using namespace std;

#ifndef _JUDGE_H
#define _JUDGE_H

class stack
{
    private:
        struct node
        {
            int data;
            node *next;
            node(const int &x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };
    public:
        node *upper;
        stack();
        ~stack();
        
        bool isEmpty();
        void push(const int &x);
        int pop();
        int top();
};

class queue
{
    public:
        struct node
        {
            int data;
            node *next;
            node(const int &x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };

        node *front, *rear;
        queue();
        ~queue();
        bool isempty();
        void enqueue(const int &x);
        int dequeue();
        int gethead(); 
};

#endif