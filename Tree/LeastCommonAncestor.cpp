/**
*   Find the Least Common Ancestor (LCA) of any two nodes in a binary tree.
*
*   For Example: In the below tree
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
*   
*
*   LCA of 4, 2 is 2
*   LCA of 5, 6 is 1
*   LCA of 6, 7 is 3
*
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:  
    int lca(TreeNode* root, int p, int q) {
        if (!root)
            return -1;
        
        if (p == root->val || q == root->val)
            return root->val;
         
        int left = lca(root->left, p, q);
        int right = lca(root->right, p, q);
        
        if (left != -1 && right != -1)
            return root->val;
        return left == -1 ? right : left;
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;

    cout<<"LCA of 4, 2 is "<<sl.lca(root, 4 , 2)<<endl;
    cout<<"LCA of 5, 6 is "<<sl.lca(root, 5 , 6)<<endl;
    cout<<"LCA of 6, 7 is "<<sl.lca(root, 6 , 7)<<endl;

    deleteTree(root);
    
    return 0;
}
