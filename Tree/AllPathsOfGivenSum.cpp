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
    void pathFromRoot(TreeNode *root, vector<vector<int> > &paths, vector<int> &path, int sum) {
        if (!root)
            return;
        
        if (sum - root->val == 0) {
            path.push_back(root->val);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        pathFromRoot(root->left, paths, path, sum - root->val);
        pathFromRoot(root->right, paths, path, sum - root->val);
        path.pop_back();
    }

    void fintAllPathsFromRoot(TreeNode *root, vector<vector<int> > &paths, vector<int> &path, int sum) {
        if (!root)
            return;
            
        pathFromRoot(root, paths, path, sum);
        pathFromRoot(root->left, paths, path, sum);
        pathFromRoot(root->right, paths, path, sum);
    }

    void findPaths(TreeNode *root, vector<vector<int> > &paths, vector<int> &path, int sum) {
        if (!root)
            return;

        findPaths(root->left, paths, path, sum);

        path.push_back(root->val);

        int tempSum = 0;

        for (int i = path.size() - 1; i >= 0 ; i--) {
            tempSum += path[i];
            if (tempSum == sum) {
                paths.push_back(vector<int>(path.begin() + i, path.end()));
                break;
            }
        }


        findPaths(root->right, paths, path, sum);
    }
    
    vector<vector<int> > allPaths(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        fintAllPathsFromRoot(root, paths, path, sum);
        findPaths(root, paths, path, sum);
        return paths;
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);

    Solution sl;
    vector<vector<int> > paths = sl.allPaths(root, 10);
    
    for (int i = 0; i < paths.size(); i++)
        printArray(paths[i]); 
    deleteTree(root);
    
    return 0;
}
