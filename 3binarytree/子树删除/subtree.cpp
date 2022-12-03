#include <iostream>
#include "subtree.h"

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

string btree::levelOrder()
{
    queue q;
    Node *tmp;
    string output;

    //cout << "LevelOrder:" << endl;
    q.enqueue(root);

    while(!q.isempty())
    {
        tmp = q.dequeue();
        output += tmp->data;
        output += " ";
        if (tmp->left != NULL)
            q.enqueue(tmp->left);
        if(tmp->right != NULL)
            q.enqueue(tmp->right);
    }
    return output;
}

void btree::createTree()
{
    queue que;
    Node *tmp;
    string x;
    cin >> x;
    root = new Node(x, size);
    size++;
    if(cin.get() == '\n'){return;}//change '\n' to EOF in educoder
    que.enqueue(root);
    while(cin >> x)
    {
        tmp = que.dequeue();
        size++;
        que.enqueue(tmp -> left = new Node(x, size));
        if(cin.get() == '\n'){break;}
        cin >> x;
        size++;
        que.enqueue(tmp -> right = new Node(x, size));
        if(cin.get() == '\n'){break;}
    }
}

//后序遍历,把中间为0的叶子节点置为null,最后为0的叶子结点删掉
btree::Node* btree::deleteLeaves(btree::Node* x, string y)
{
    if (x == NULL)return x;
    x -> right = deleteLeaves(x -> right, y);
    x -> left = deleteLeaves(x -> left, y);
    if ((x -> data == y || x -> data == "null") && (x -> left == NULL || x -> left -> data == "null") && (x -> right == NULL || x -> right -> data == "null")) 
    {
        if(x == root)cout << "null";//删除根节点
        if(x -> number == size){delete x; x= NULL; size--; return x;}//删除最后一个叶子节点
        else{
                x -> data = "null";
                return x;
            }
    };
    return x;
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
