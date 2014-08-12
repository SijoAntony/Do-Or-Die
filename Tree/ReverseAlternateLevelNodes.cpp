/**

    Given a Perfect Binary Tree, reverse the alternate level nodes of the binary tree.
    
    Examples:

        Given tree: 
                       a
                    /     \
                   b       c
                 /  \     /  \
                d    e    f    g
               / \  / \  / \  / \
               h  i j  k l  m  n  o 
        
        Modified tree:
          	           a
                    /     \
                   c       b
                 /  \     /  \
                d    e    f    g
               / \  / \  / \  / \
              o  n m  l k  j  i  h 
**/

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void getNodesAltLevel(TreeNode* root, vector<int>& nodes, bool level) {
        if (!root)
            return;

        getNodesAltLevel(root->left, nodes, !level);
        if (level )
            nodes.push_back(root->val);
        getNodesAltLevel(root->right, nodes, !level);
    }

    void setNodesAltLevel(TreeNode* root, vector<int>& nodes, bool level) {
        if (!root)
            return;

        setNodesAltLevel(root->left, nodes, !level);
        if (level) {
            root->val = nodes.front();
            nodes.erase(nodes.begin());
        }
        setNodesAltLevel(root->right, nodes, !level);
    }
    
    void revrseAltLevelNodes(TreeNode* root) {
        if (!root)
            return;
        
        vector<int> nodes;
        getNodesAltLevel(root, nodes, false);
        reverse(nodes.begin(), nodes.end());
        setNodesAltLevel(root, nodes, false);
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    treeInorder(root);cout<<endl;

    Solution sl;
    sl.revrseAltLevelNodes(root);
    treeInorder(root);    

    deleteTree(root);
    
    return 0;
}
