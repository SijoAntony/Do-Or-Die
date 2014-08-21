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
    bool match(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2)
            return false;
         
        return (t1->val == t2->val) && match(t1->left, t2->left) && match(t1->right, t2->right);
    }
    bool isSubTree(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return true;

        if (!t2 || !t1)
            return false;
        
         if (match(t1, t2))
            return true;
               
        return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;

    deleteTree(root);
    
    return 0;
}
