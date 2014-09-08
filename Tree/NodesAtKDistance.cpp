/**
*   Given a binary tree, a target node in the binary tree, and an integer value k, 
*   print all the nodes that are at distance k from the given target node. No parent pointers are available.
*
*   Examples:
*       Consider the tree shown in diagram
*       Input: 
*           Target = node with data 8. 
*           Root = node with data 20.
*           k = 2.
*       Output : 10 14 22
*   
*       If Target is 14 and k is 3, then Output should be "4 20"
*
*
*         20
*       /   \
*      8    22
*     / \
*    4   12
*       /  \
*      10  14
*
**/

#include <iostream>
#include <set>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    //Find nodes descendeing from a given node
    void printNodesAtKDistanceFromRoot(TreeNode* root, int k) {
        if (!root)
            return;
            
        if(k == 0)
            cout<<root->val<<" ";
        
        printNodesAtKDistanceFromRoot(root->left, k - 1);
        printNodesAtKDistanceFromRoot(root->right, k - 1);
    }
    
    int printNodesAtKDistance(TreeNode* root, int target, int k) {
        if (!root)
            return -1;

        //Case 1 : If root itself is the target node!
        if (root->val == target) {
            printNodesAtKDistanceFromRoot(root, k);
            return 0;
        }
        
        //Case 2: Check Target is on left subtree
        int m = printNodesAtKDistance(root->left, target, k);
        if (m != -1) {
            if (m + 1 == k)
                cout<<root->val<<" ";
            else
                // Substract 2 becoz right node is 2 edges away from left node
                printNodesAtKDistanceFromRoot(root->right, k - m - 2); 
            return m + 1;
        }

        //Case 3: Check Target is on right subtree
        m = printNodesAtKDistance(root->right, target, k);        
        if (m != -1) {
            if (m + 1 == k)
                cout<<root->val<<" ";
            else
                printNodesAtKDistanceFromRoot(root->left, k - m - 2);
            return m + 1;
        }
        return -1;
    }
    
    void printNodesAtKDistanceFromLeaf(TreeNode *root, int k, vector<int>& ancestors, set<int> &nodes) {
        if (!root)
            return;

        if (isLeaf(root) && ancestors.size() >= k) {
            nodes.insert(ancestors[ancestors.size() - k]);
        }
        
        ancestors.push_back(root->val);
        printNodesAtKDistanceFromLeaf(root->left, k, ancestors, nodes);
        printNodesAtKDistanceFromLeaf(root->right, k, ancestors, nodes);
        ancestors.pop_back();
    }
    
    void printNodesAtKDistanceFromLeaf(TreeNode *root, int k) {
        if (!root)
            return;
        vector<int> ancestors;
        set<int> nodes;
        printNodesAtKDistanceFromLeaf(root, k, ancestors, nodes);
        
        for (set<int>::iterator it = nodes.begin();  it != nodes.end(); it++)
            cout<<*it<<" ";
    }
};

int main()
{
    string str = "20 8 4 # # 12 10 # # 14 # # 22";
    
    TreeNode* root = buildTree(str);
    Solution sl;
    //sl.printNodesAtKDistance(root, 14, 3);
    sl.printNodesAtKDistanceFromLeaf(root, 1);
    deleteTree(root);
    
    return 0;
}
