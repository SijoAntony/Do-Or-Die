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
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    
    TreeNode *formBST(vector<int> &preorder, int &index, int min, int max) {
        if (preorder.size() == index || preorder[index] > max || preorder[index] < min)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = formBST(preorder, index, min, root->val);
        root->right = formBST(preorder, index, root->val, max);
        
        return root;
    }
    
    TreeNode *formBST(vector<int> &preorder) {
        int index = 0;
        return formBST(preorder, index, INT_MIN, INT_MAX);
    }
};

int main()
{
    int A[] = {8,3,1,6,4,7,10,14,13};
    vector<int> preorder(A, A + sizeof(A) / sizeof(int));
    
    Solution sl;
    TreeNode* root = sl.formBST(preorder);
    treePreorder(root); 
    deleteTree(root);
    
    return 0;
}
