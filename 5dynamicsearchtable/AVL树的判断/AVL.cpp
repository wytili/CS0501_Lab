#include <iostream>
#include "AVL.h"
using namespace std;

void AvlTree::createTree()
{
    queue que;
    AvlNode *tmp;
    string x;
    flag = 1;
    cin >> x;
    root = new AvlNode(x);
    if(cin.get() == '\n'){/*cout<< "created!" << endl;*/ return;}//change '\n' to EOF in online judging
    que.enqueue(root);
    while(cin >> x)
    {
        tmp = que.dequeue();
        que.enqueue(tmp -> left = new AvlNode(x));
        if(cin.get() == '\n'){break;}
        cin >> x;
        que.enqueue(tmp -> right = new AvlNode(x));
        if(cin.get() == '\n'){break;}
    }
    // cout << "created!" << endl;
}

void AvlTree::isAVL(AvlNode *t)
{
    if(t == NULL ||t -> data == "null")return;
    else if(abs(height(t -> left) - height(t -> right)) > 1)
    {
        flag = 0;
    }
    else
    {
        isAVL(t -> left);
        isAVL(t -> right);
    }
}

int AvlTree::height(AvlNode *t)
{
    if(t == NULL ||t -> data == "null")return 0;
    else
    {
        int lt = height(t -> left), rt = height(t -> right);
        return 1 + ((lt > rt)?lt : rt);
    }
}

void AvlTree::printTree()
{
    queue que;
    AvlNode *tmp;
    cout << "levelorder:";
    que.enqueue(root);
    while (!que.isempty()) {
    tmp = que.dequeue();
    cout << tmp->data << "'s height is" << height(tmp) << endl;
    if (tmp->left) que.enqueue(tmp->left);
    if (tmp->right) que.enqueue(tmp->right);
    }
    cout << endl;
}

void AvlTree::makeEmpty(AvlNode *&t) 
{
    if (t == NULL || t -> data == "null") return;
    AvlNode *tmp = t;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete tmp;
    t = NULL;
}

queue::queue()
{
    front = rear = NULL;
}

queue::~queue()
{
    node *tmp;
    while(front != NULL)
    {
        tmp = front;
        front = front -> next;
        delete tmp;
    }
}

void queue::enqueue( AvlTree::AvlNode *x)
{
    if(isempty())
        {front = rear = new node(x);}
    else
        {rear = rear -> next = new node(x);}
}

 AvlTree::AvlNode *queue::dequeue()
{
    node *tmp = front;
     AvlTree::AvlNode *x = tmp -> data;
    front = front -> next;
    if(front == NULL){rear = NULL;}
    delete tmp;
    return x;
}

bool queue::isempty()
{
    return front == NULL;
}

// void AvlTree::insert(const string &x, AvlNode *&t) 
// {
//     if (t == NULL) 
//     {
//         t = new AvlNode(x, NULL, NULL);
//     } 
//     else if (x < t->data) 
//     {
//         insert(x, t->left);
//         if (height(t->left) - height(t->right) == 2) 
//         {
//             if (x < t->left->data) 
//             {
//                 LL(t);
//             } 
//             else 
//             {
//                 LR(t);
//             }
//         }
//         t->height = height(t->left) + height(t->right) + 1;
//     } 
//     else if (x > t->data) 
//     {
//         insert(x, t->right);
//         if (height(t->right) - height(t->left) == 2) 
//         {
//             if (x > t->right->data) 
//             {
//                 RR(t);
//             } 
//             else 
//             {
//                 RL(t);
//             }
//         }
//     }
//         t->height = max(height(t->left) + height(t->right)) + 1;
// }

 
// bool AvlTree::remove(const string &x, AvlNode *&t) 
// {
//     if (t == NULL) 
//     {
//         return true;
//     }
//     if (x == t->data) 
//     {
//         if(t -> left == NULL || t -> right == NULL)
//         {
//             AvlNode *oldNode = t;
//             t = (t -> left != NULL)?t -> left : t -> right;
//             delete oldNode;
//             return false;
//         }
//         else
//         {
//             AvlNode *tmp = t ->right;
//             while(tmp -> left != NULL)tmp = tmp -> left;
//             t -> data = tmp -> data;
//             if(remove(tmp -> data, t -> right))return true;
//             return adjust(t, 1);
//         }
//     } 
//     if(x < t -> data)
//     {
//         if(remove(x, t -> left))return true;
//         return adjust(t, 0);
//     }
//     else
//     {
//         if(remove(x, t -> right))return true;
//         return adjust(t, 1);
//     }
// }

// bool AvlTree::adjust(AvlNode *&t, string subtree)
// {
//     if(subtree)
//     {
//         if(height(t -> left) - height(t -> right) == 1)return true;
//         if(height(t -> left) == height(t -> right)){--t -> height; return false;}
//         if(height(t -> left -> right) > height(t -> left -> left)){LR(t); return false;}
//         LL(t);
//         if(height(t -> left) == height(t -> right)){return false;}
//         else return true;
//     }
//     else 
//     {
//         if(height(t -> right) - height(t -> left) == 1)return true;
//         if(height(t -> right) == height(t -> left)){--t -> height; return false;}
//         if(height(t -> right -> left) > height(t -> right -> right)){RL(t); return false;}
//         RR(t);
//         if(height(t -> right) == height(t -> left)){return false;}
//         else return true;
//     }
// }

 
// string* AvlTree::find(const string &x) const 
// {
//     AvlNode *t = root;
//     while(t != NULL && t -> data != x)
//     {
//         if(t -> data > x)t = t -> left;
//         else t = t -> right;
//     }
//     if(t == NULL)return NULL;
//     else return (string *)t;
// }


// void AvlTree::LL(AvlNode *&t) 
// {
//     AvlNode *t1 = t->left;
//     t->left = t1->right;
//     t1->right = t;
//     t->height = max(height(t->left) + height(t->right)) + 1;
//     t1->height = max(height(t1->left) + height(t)) + 1;
//     t = t1;
// }

 
// void AvlTree::RR(AvlNode *&t) 
// {
//     AvlNode *t1 = t->right;
//     t->right = t1->left;
//     t1->left = t;
//     t->height = max(height(t->left) + height(t->right)) + 1;
//     t1->height = max(height(t1->right) + height(t)) + 1;
//     t = t1;
// }

 
// void AvlTree::LR(AvlNode *&t) 
// {
//     RR(t->left);
//     LL(t);
// }

 
// void AvlTree::RL(AvlNode *&t) 
// {
//     LL(t->right);
//     RR(t);
// }