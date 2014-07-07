/**
*   Find the circumference of the tree. Circumference is side nodes of tree
*
*   Examples:
*
*                   1
*                /    \
*               2      3
*              / \    / \
*             4   5  6   7
*              \  / /   / \
*              14 8 9  10 11
*             / \        /
*            16  15     12
*                      /
*                     13
*
*   Circumference of above is:1, 2, 4, 14, 16, 15, 8, 9, 10, 13, 12, 11, 7, 3
*
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    
    void printLeftEdge(TreeNode* root) {
        if (!root)
            return;
            
        if (root->left || root->right)
            cout<<root->val<<" ";
        
        root->left ? printLeftEdge(root->left) : printLeftEdge(root->right);
    }
    
    void printLeaves(TreeNode* root) {
        if (!root)
            return;

        if (!root->left && !root->right)
            cout<<root->val<<" ";

        printLeaves(root->left);
        printLeaves(root->right);
    }
    
    void printRightEdge(TreeNode* root) {
        if (!root)
            return;

        root->right ? printRightEdge(root->right) : printRightEdge(root->left);        

        if (root->left || root->right)
            cout<<root->val<<" ";

    }
    
    void printCicumferenceOfTree(TreeNode* root) {
        if (!root)
            return;
        
        //Print root itself
        cout<<root->val<<" ";
        
        printLeftEdge(root->left);  // left edge
        printLeaves(root);          // leaves
        printRightEdge(root->right);// right edge
    }

};

int main()
{
    string str = "1 2 4 # 14 16 # # 15 # # 5 8 # # # 3 6 9 # # # 7 10 # # 11 12 13 # # # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    sl.printCicumferenceOfTree(root);
    deleteTree(root);
    
    return 0;
}
