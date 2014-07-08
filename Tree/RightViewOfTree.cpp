/**
*   Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes 
*   visible when tree is visited from Right side.
*
*   Examples:
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
*   /   / \
*  8   9  10
*     /
*    11   
*   Right view of above tree is 1 3 7 10 11
* 
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void printRightView(TreeNode* root, int& height, int currentHeight) {
        if (!root)
            return;
        if (currentHeight + 1 > height) {
            cout<<root->val<<" ";
            height = currentHeight + 1;
        }
        printRightView(root->right, height, currentHeight + 1);
        printRightView(root->left, height, currentHeight + 1);
    }
    
    void printRightView(TreeNode* root) {
        int height = 0;
        printRightView(root, height, 0);
    }
};

int main()
{
    string str = "1 2 4 8 # # # 5 9 11 # # # 10 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    sl.printRightView(root);
    deleteTree(root);
    
    return 0;
}
