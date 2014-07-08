/**
*   Find the maximum path sum between two leaves of a binary tree. 
*
*   Examples:
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
*
*   The maximum sum path may or may not go through root.  
*   In above binary tree, the maximum sum is 18 (5 + 2 + 1 + 3 + 7)
*
*
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;
            
        int leftSum = maxPathSum(root->left, maxSum);   // max of left subtree
        int rightSum = maxPathSum(root->right, maxSum); // max of right subtree
        int maxChild = max(leftSum, rightSum);          // max of children
        int sum = leftSum + rightSum + root->val;       // sum including root

        maxSum = max(maxSum, max(maxChild, sum));       //max of path sum
        
        return maxChild + root->val;                    //return the max value till this node
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = 0;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};

int main()
{
    string str = "-15 5 -8 2 # # 6 # # 1 # # 6 3 # # 9 # 0 4 # # -1 10 # # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    cout<<"Max path sum between leaves: "<<sl.maxPathSum(root);
    deleteTree(root);
    
    return 0;
}
