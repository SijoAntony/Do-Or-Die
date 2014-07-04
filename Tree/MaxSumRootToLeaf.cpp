/**
*   Given a Binary Tree, find the maximum sum path from a leaf to root. 
*   
*   For example, in the following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. 
*   The sums of these three paths are 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10.
*
*                  10
*                /    \
*	           -2      7
*             /   \     
*       	 8    -4    
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void maxSumRootToLeaf(TreeNode* root, int sum, int &maxSum) {
        if (!root)
            return;
            
        if ( !root->left && !root->right && sum + root->val > maxSum) {
            maxSum = sum + root->val;
            return;
        }

        maxSumRootToLeaf(root->left, sum + root->val, maxSum);
        maxSumRootToLeaf(root->right, sum + root->val, maxSum);
    }
 
    int maxSumRootToLeaf(TreeNode* root) {
        int sum = 0;
        maxSumRootToLeaf(root, 0, sum);
        return sum;
    }
};

int main()
{
    string str = "10 -2 8 # # -4 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    cout<<"Max sum from root to any leaf paths: "<<sl.maxSumRootToLeaf(root);

    deleteTree(root);
    
    return 0;
}
