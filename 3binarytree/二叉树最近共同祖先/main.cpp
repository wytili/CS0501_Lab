#include <iostream>
#include "lca.h"
using namespace std;

int main()
{
    btree tree;
    tree.createTree();
    int x, y;
    cin >> x >> y;
    tree.Ancester(tree.findNode(x, tree.root), tree.findNode(y, tree.root));
}

