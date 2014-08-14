/**
*   Find path between two nodes in a tree.
*   Examples:
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
*
*   In tha above tree, path between 4, 7 is - 4 , 2, 7, 3, 1
*
**/

#include <iostream>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
 
    bool path(TreeNode *root, int a, int b, vector<int>& nodes) {
        if (!root)
            return false;
            
        bool left = path(root->left, a, b, nodes);
        bool right = path(root->right, a, b, nodes);

        if (root->val == a || root->val == b) {
            nodes.push_back(root->val);
            return true;
        }

        if (left && right) {
            nodes.push_back(root->val);
            return false;
        }

        if (left || right) {
            nodes.push_back(root->val);
            return true;
        }
        
        return false;
    }
    
    vector<int> path(TreeNode *root, int a, int b) {
        vector<int> nodes;
        path(root, a, b, nodes);
        return nodes;
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    
    vector<int> nodes = sl.path(root, 4, 7);
    for(int i = 0; i < nodes.size(); i++)
        cout<<nodes[i]<<" ";
    
    deleteTree(root);
    
    return 0;
}
