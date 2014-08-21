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
    bool  isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int lh = 0, rh = 0;
        bool left =  isBalanced(root->left, lh);
        bool right =  isBalanced(root->right, rh);
        
        height = max(lh, rh) + 1;

        return left && right && abs(lh - rh) <= 1;
        
    }
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalanced(root, height);
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 8 9 # # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    cout<<"Tree is balanced ? : "<<sl.isBalanced(root);
    deleteTree(root);
    
    return 0;
}
