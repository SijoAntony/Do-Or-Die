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
    bool rootToLeafSumExists(TreeNode *root, int sum) {
        if (!root)
            return false;
            
        int subSum = sum - root->val;

        //did sum match at the leaft
        if (isLeaf(root))
            return subSum == 0 ? true : false;
        
        //Check subtrees further. Note shotcut evaluation
        //right subtree is checked only if sum is not on left subtree
        return rootToLeafSumExists(root->left, subSum) 
                || rootToLeafSumExists(root->right, subSum);
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);

    Solution sl;
    cout<<"Found sum? "<<sl.rootToLeafSumExists(root, 10);

    deleteTree(root);
    
    return 0;
}
