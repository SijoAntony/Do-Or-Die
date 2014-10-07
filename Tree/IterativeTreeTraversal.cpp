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

void interativeInorder(TreeNode *root)
{
    while (root) {
        if (!root->left) {
            cout<<root->val<<" ";
            root = root->right;
        } else {
            TreeNode *current = root->left;
            while (current->right && current->right != root)
                current = current->right;
            
            if (!current->right) {
                current->right = root;
                root = root->left;
            } else {
                cout<<root->val<<" ";
                current->right = NULL;
                root = root->right;
            }
        }
    }
    
}

void iterativePreorder(TreeNode *root) {
    while (root) {
        if (!root->left) {
            cout<<root->val<<" ";
            root = root->right;
        } else {
            TreeNode *current = root->left;
            while (current->right && current->right != root)
                current = current->right;
            
            if (current->right == root) {
                current->right = NULL;
                root = root->right;    
            } else {
                cout<<root->val<<" ";
                current->right = root;
                root= root->left;
            }
        }
    }
}

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);
    
    interativeInorder(root);cout<<endl;
    iterativePreorder(root);
    
    deleteTree(root);
    
    return 0;
}
