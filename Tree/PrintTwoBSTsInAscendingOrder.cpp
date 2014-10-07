/**
*   Examples:
*
*         4
*       /   \
*      2     6
*     / \   / \
*    1   3 5   7
**/

#include <iostream>
#include <vector>
#include <stack>

#include "../Arrays/ArrayUtils.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    
    void fill(TreeNode *r, vector<int> &result) {
        if (!r)
            return;
            
        fill(r->left, result);
        result.push_back(r->val);
        fill(r->right, result);
    }
    
    void merge(TreeNode *r1, TreeNode *r2, vector<int> &result) {
        if (!r1 && !r2)
            return;
        
        if (!r1) {
            fill(r2, result);
            return;
        }

        if (!r2) {
            fill(r1, result);
            return;
        }        
        
        if (r1->val > r2->val) {
            merge(r1->left, r2, result);
            result.push_back(r1->val);
            fill(r1->right,result);
        }
        else if (r1->val < r2->val) {
            merge(r1, r2->left, result);
            result.push_back(r2->val);
            fill(r2->right, result);
        }
        else {
            merge(r1->left, r2->left, result);
            result.push_back(r1->val);
            result.push_back(r2->val);
            merge(r1->right, r2->right, result);
        }
    }
    
    vector<int> mergeTwoBSTsInASCOrder(TreeNode *r1, TreeNode *r2) {
        vector<int> result;
        //merge(r1, r2, result);
        stack<TreeNode*> s1, s2;
        bool done = false;
        
        while (!done) {
            if (r1 && r2) {
                s1.push(r1);
                r1 = r1->left;
                s2.push(r2);
                r2 = r2->left;
            }
            else if (r1 && !r2) {
                s1.push(r1);
                r1 = r1->left;
            }
            else if (!r1 && r2) {
                s2.push(r2);
                r2 = r2->left;
            }
            else {
    
                if (!s1.empty() && !s1.empty()) {
                    if (s1.top()->val < s2.top()->val) {
                        r1 = s1.top();
                        result.push_back(r1->val);
                        s1.pop();
                        r1 = r1->right;
                    }else {
                        r2 = s2.top();
                        result.push_back(r2->val);
                        s2.pop();
                        r2 = r2->right;
                    }
                } else if (s1.empty() && !s2.empty()) {
                    r2 = s2.top();
                    result.push_back(r2->val);
                    s2.pop();
                    r2 = r2->right;
                    
                }else if (s2.empty() && !s1.empty()) {
                    r1 = s1.top();
                    result.push_back(r1->val);
                    s1.pop();
                    r1 = r1->right;
                }
                else {
                    done = true;
                }
            }
        }
        
        return result;
    }
};

void iterativePreorder(TreeNode *root)
{
    while (root) {
        if (!root->left) {
            cout<<root->val<<" ";    
            root = root->right;
        }
        else {
            TreeNode *right = root->left;
            while(right->right && right->right != root)
                right = right->right;
            
            if (right->right == root) {
                right->right = NULL;
                root = root->right;
            }else {
                right->right = root;
                cout<<root->val<<" ";
                root = root->left;    
            }
        }
        
    }
}

int main()
{
    string strOne = "8 2 1 # # 3 # # 10 9 # # 11 # #";
    string strTwo = "6 3 2 # # 5 # # 8 7 # # 9 # #";
    
    
    TreeNode* one = buildTree(strOne);
    TreeNode* two = buildTree(strTwo);
    
    Solution sl;
    vector<int> result = sl.mergeTwoBSTsInASCOrder(one, two);
    printArray(result);

    deleteTree(one);
    deleteTree(two);
    
    return 0;
}
