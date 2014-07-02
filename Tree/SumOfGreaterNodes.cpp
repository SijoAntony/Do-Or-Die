/**
*    Given a Binary Search Tree (BST), convert it to a Binary Tree such that every key of the original 
*    BST is changed to key plus sum of all greater keys in BST.
*    
*    Examples:
*    
*    Input: Root of following BST
*                  5
*                /   \
*               2     13
*    
*    Output: The given BST is converted to following Binary Tree
*                  18
*                /   \
*              20     13
*              
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {

public:
    int addGreaterNodes(TreeNode* root, int value) {
        if (!root)
            return value;
            
        int right = addGreaterNodes(root->right, value);
        int left = addGreaterNodes(root->left, root->val += right);
        
        return left;
    }
    
};

int main()
{
    string str = "5 3 2 1 # # # 4 # # 7 6 # # 8 # #";
    
    TreeNode* root = buildTree(str);
    cout<<"\nBefore"; treeInorder(root);

    Solution sl;
    sl.addGreaterNodes(root, 0);

    cout<<"\nAfter"; treeInorder(root);
    
    deleteTree(root);
    
    return 0;
}
