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
#include "../Arrays/ArrayUtils.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void treeToMatrix(TreeNode *root, vector<vector<int> > &matrix, vector<int> &path) {
        if (!root)
            return;
        
        for (int i = 0; i < path.size(); i++) {
            matrix[path[i]][root->val] = 1;
        }

        path.push_back(root->val);
        treeToMatrix(root->left, matrix, path);
        treeToMatrix(root->right, matrix, path);
        path.pop_back();
    }
    
    vector<vector<int> > treeToMatrix(TreeNode *root, int n) {
        vector<vector<int> > matrix (n + 1, vector<int>(n + 1, 0));
        vector<int> path;
        treeToMatrix(root, matrix, path);
        
        return matrix;
    }
        
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    vector<vector<int> > v = sl.treeToMatrix(root, 7);
    printMatrix(v);
    deleteTree(root);
    
    return 0;
}
