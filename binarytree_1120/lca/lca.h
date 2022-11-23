#include <iostream>
using namespace std;

#ifndef _LCA_H
#define _LCA_H

class btree
{
    public:
        struct Node
        {
            string data;
            int number;//�������
            int flag;//0����û������1����������һ�����ĸ���㣬2�����Ƕ��߹�ͬ�ĸ����
            Node *left, *right, *ldad, *rdad;
            Node(): flag(0), left(NULL), right(NULL), ldad(NULL), rdad(NULL){}
            Node(string item, int num, int f = 0, Node *Lc = NULL, Node *Rc = NULL, Node *Ld = NULL, Node *Rd = NULL):data(item), number(num), flag(f), left(Lc), right(Rc), ldad(Ld), rdad(Rd){}
            ~Node(){}
        };
        int size;//���Ĵ�С���������
        Node *root;
        btree():size(1), root(NULL){}
        btree(string x){root = new Node(x, 1, 0); size = 1;}
        ~btree();
        void clear(Node *&t);
        void createTree();
        void levelOrder();
        Node* findNode(int n, Node* t);
        void Ancester(Node *a, Node* b);
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