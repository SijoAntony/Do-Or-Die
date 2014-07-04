/**
*   Given a binary tree, print out the tree in zig zag level order (ie, from left to right, then right 
*   to left for the next level and alternate between). Output a newline after the end of each level.
*
*   For example, for tree below
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
*
*   The zig zag level order output is :
*
*   1
*   3 2
*   4 5 6 7
*   
**/

#include <iostream>
#include <stack>
#include <deque>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void traverseTreeZigZagV2(TreeNode *root) {
        if (!root)
            return;

        stack<TreeNode*> current, next;
        bool forward = true;
        current.push(root);

        while (!current.empty()) {
            TreeNode* n = current.top();
            current.pop();
            
            if (n) {
                cout<<n->val<<" ";
                if (forward) {
                    next.push(n->left);
                    next.push(n->right);
                }
                else {
                    next.push(n->right);
                    next.push(n->left);
                }
            }
            
            if (current.empty()) {
                swap(current, next);
                forward = !forward;
                cout<<endl;
            }
        }
    }
    void traverseTreeZigZagV1(TreeNode *root) {
        if (!root)
            return;
        deque<TreeNode*> nodeDQ;
        nodeDQ.push_back(root);
        
        int parents = 1;
        int children  = 0;
        bool forward = true;
        
        while(!nodeDQ.empty()) {
            TreeNode *n = forward ? nodeDQ.front() : nodeDQ.back();
            forward ? nodeDQ.pop_front() : nodeDQ.pop_back();
            parents--;

            if (n) {
                cout<<n->val<<" ";
    
                if (forward) {
                    nodeDQ.push_back(n->left);
                    nodeDQ.push_back(n->right);
                    children += 2;
                }
                else {
                    nodeDQ.push_front(n->right);
                    nodeDQ.push_front(n->left);
                    children += 2;
                }
            }
            if (parents == 0) {
                parents = children;
                children = 0;
                forward = !forward;
                cout<<endl;
            }
        }
    }
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    
    Solution sl;
    sl.traverseTreeZigZagV2(root);
    
    deleteTree(root);
    
    return 0;
}
