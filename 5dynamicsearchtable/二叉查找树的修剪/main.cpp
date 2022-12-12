#include <iostream>
#include "BST.h"
using namespace std;
//trimBST采用递归思想，从节点开始，若满足范围则对左右结点继续判断，若不满足则remove后对该节点再次判断
int main()
{
    BiSearchTree tree;
    tree.createTree();
    int low, high;
    cin >> low;
    if(cin.get() == '\n')high = low;//change to EOF in online judging
    else cin >> high;
    tree.trimBST(low, high, tree.root);
    if(tree.root == NULL || tree.root -> data == "null")cout << "null";
    else
    {
        tree.levelOrder();
    }
}