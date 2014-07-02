/**
*
*   Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*    
*   For example, this binary tree is symmetric:
*    
*        1
*       / \
*      2   2
*     / \ / \
*    3  4 4  3
*
*   But the following is not:
*        1
*       / \
*      2   2
*       \   \
*       3    3
*   
*
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {

public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (left && right && left->val == right->val) {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};


int main()
{
    string unSymmetric = "30 10 50 # # # 20 45 # # 35"; //unsymmetric tree
    string symmetric = "1 2 3 # # 4 # # 2 4 # # 3"; //symmetric tree
    
    TreeNode* uroot = buildTree(unSymmetric);
    TreeNode* sroot = buildTree(symmetric);
    
    Solution sl;
    
    cout<<"->"<<sl.isSymmetric(uroot)<<endl;
    cout<<"->"<<sl.isSymmetric(sroot)<<endl;
    
    deleteTree(uroot);
    deleteTree(sroot);
    
    return 0;
}
