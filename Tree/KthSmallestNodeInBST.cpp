/**
*   Examples:
*
*         4
*       /   \
*      2     6
*     / \   / \
*    1   3 5   7
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    
    int kthSmallest(TreeNode *root, int &index, int k) {
        if (!root)
            return 0;

        int left = kthSmallest(root->left, index, k);

        if (index == k)
            return left;
        else if (k == ++index) 
            return root->val;
        return kthSmallest(root->right, index, k);
    }
    
    int kthSmallest(TreeNode *root, int k) {
        if (!root)
            return 0;
        int index = 0;
        return kthSmallest(root, index, k);
    }
};

int main()
{
    string str = "14 10 9 # # 11 # # 16 15 # # 17 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    cout<<sl.kthSmallest(root, 2);
    deleteTree(root);
    
    return 0;
}
