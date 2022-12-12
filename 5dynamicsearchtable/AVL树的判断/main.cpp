#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    AvlTree tree;
    tree.createTree();
    tree.isAVL(tree.root);
    if(tree.flag == 1)cout << "true";
    if(tree.flag == 0)cout << "false";
}