#include <iostream>
#include "single.h"

using namespace std;

btree::~btree()
{
    clear(root);
}

void btree::clear(Node *&t)
{
    if(t == NULL) return;
    clear(t -> left);
    clear(t -> right);
    delete t;
    t = NULL;
}

//delete Node whose data is "null"
void btree::delnull(Node *&t)
{
    if(t -> data == "null"){clear(t);}
    else 
        {
            if(t -> left != NULL) delnull(t -> left);
            if(t -> right != NULL) delnull(t -> right);
        }

}

// void btree::levelOrder()
// {
//     queue q;
//     Node *tmp;

//     cout << "LevelOrder:" << endl;
//     q.enqueue(root);

//     while(!q.isempty())
//     {
//         tmp = q.dequeue();
//         cout << tmp->data << " ";
//         if (tmp->left)
//             q.enqueue(tmp->left);
//         if(tmp->right)
//             q.enqueue(tmp->right);
//     }
// }

void btree::createTree()
{
    queue que;
    Node *tmp;
    string x;
    cin >> x;
    root = new Node(x);
    if(cin.get() == '\n'){/*cout<< "created!" << endl;*/ return;}//change '\n' to EOF in online judging
    que.enqueue(root);
    while(cin >> x)
    {
        tmp = que.dequeue();
        que.enqueue(tmp -> left = new Node(x));
        if(cin.get() == '\n'){break;}
        cin >> x;
        que.enqueue(tmp -> right = new Node(x));
        if(cin.get() == '\n'){break;}
    }
    //cout << "created!" << endl;
}

int btree::countSingle(Node *t)
{
    if(t == NULL){return 0;}
    if((t -> left && !t -> right))
    {
        return 1 + countSingle(t -> left);
    }
    if(t -> right && !t -> left)
    {
        return 1 + countSingle(t ->right);
    }
    else
        return countSingle(t -> left) + countSingle(t ->right);
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

void queue::enqueue(btree::Node *x)
{
    if(isempty())
        {front = rear = new node(x);}
    else
        {rear = rear -> next = new node(x);}
}

btree::Node *queue::dequeue()
{
    node *tmp = front;
    btree::Node *x = tmp -> data;
    front = front -> next;
    if(front == NULL){rear = NULL;}
    delete tmp;
    return x;
}

bool queue::isempty()
{
    return front == NULL;
}
