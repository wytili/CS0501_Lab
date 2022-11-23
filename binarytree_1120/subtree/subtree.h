#include <iostream>
using namespace std;

#ifndef _SUBTREE_H
#define _SUBTREE_H

class btree
{
    public:
        struct Node
        {
            string data;
            int number;//结点的序号，用于和size作比较找出最后一个叶子结点
            Node *left, *right;
            Node(): left(NULL), right(NULL){}
            Node(string item, int num, Node *L = NULL, Node *R = NULL):data(item), number(num), left(L), right(R){}
            ~Node(){}
        };
        int size;//树的大小，结点数量-1
        Node *root;
        btree():size(0), root(NULL){}
        btree(string x){root = new Node(x, 1); size = 0;}
        ~btree();
        void clear(Node *&t);
        void createTree();
        string levelOrder();
        Node* deleteLeaves(Node* x, string y);
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