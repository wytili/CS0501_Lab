#include <iostream>
using namespace std;

#ifndef _SINGLE_H
#define _SINGLE_H

class btree
{
    public:
        struct Node
        {
            string data;
            Node *left, *right;
            Node(): left(NULL), right(NULL){}
            Node(string item, Node *L = NULL, Node *R = NULL):data(item), left(L), right(R){}
            ~Node(){}
        };
        Node *root;
        btree():root(NULL){}
        btree(string x){root = new Node(x);}
        ~btree();
        void clear(Node *&t);
        int countSingle(Node *t);
        void delnull(Node *&t);
        void createTree();
        void levelOrder();
};

class queue
{
    public:
        struct node
        {
            btree::Node *data;
            node *next;
            node(btree::Node *x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };

        node *front, *rear;
        queue();
        ~queue();
        bool isempty();
        void enqueue(btree::Node *x);
        btree::Node *dequeue();
};

#endif