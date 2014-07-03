/**
* The diameter of a tree (sometimes called the width) is the number of nodes 
* on the longest path between two leaves in the tree. 
*
* For example, this binary tree below diameter is 5:
*    
*        1
*       / \
*      2   2
*     / \ / \
*    3  4 4  3
*
*
* Similarly diameter for below is 6:
*    
*        1
*       / \
*      2   2
*     / \ 
*    3   4 
*   /     \
*  6       7
*           \
*            8
*
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int diameter(TreeNode* root, int& maxDiameter) {
        if (!root)
            return 0;

         int leftHight = diameter(root->left, maxDiameter);
         int rightHight = diameter(root->right, maxDiameter);

         if (leftHight + rightHight + 1 > maxDiameter)
            maxDiameter = leftHight + rightHight + 1;

         return (leftHight > rightHight ? leftHight : rightHight) + 1;
    }
    
    int diameter(TreeNode* root) {
        int maxDiameter = 0;
        diameter(root, maxDiameter);
        return maxDiameter;
    }
};

int main()
{
    string one = "1 2 3 # # 4 # # 2 4 # # 3 # #";
    string two = "1 2 3 6 # # # 4 # 7 # 8 # # 2 # #";
    
    Solution sl;
    
    TreeNode* rootOne = buildTree(one);
    cout<<"Diameter of one : "<<sl.diameter(rootOne)<<endl;
    
    TreeNode* rootTwo = buildTree(two);
    cout<<"Diameter of two : "<<sl.diameter(rootTwo)<<endl;
    
    deleteTree(rootOne);    
    deleteTree(rootTwo);
    
    return 0;
}
