/**
*   Examples:
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isCousin(TreeNode* root, int p, int q)
    {
        if (!root)
            return false;
        
        TreeNode *pp, *qp;
        
        int plevel = level(root, p, pp, 0);
        int qlevel = level(root, q, qp, 0);
        
        if (qlevel == plevel && pp != qp)
            return true;
        return false;    
    }
    
    int level(TreeNode *root, int p, TreeNode *& parent, int l)
    {
        if (!root)
            return 0;

        if ((root->left && root->left->val == p) 
            || (root->right && root->right->val == p)) {
            parent = root;
            return l + 1;
        }
        
        int r = level(root->left, p, parent, l + 1);
        
        return r > 0 ? r : level(root->right, p, parent, l + 1); 
    }

};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    cout<<"Cousines : "<<sl.isCousin(root, 7 ,5);
    deleteTree(root);
    
    return 0;
}
