/**
 * Definition for binary tree
 *
 **/
#include <sstream>
#include <string>
#include <cstdlib>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool getNextToken(std::stringstream &ss, int &token, bool &isNumber)
{
    if (ss.eof()) return false;
    
    std::string str = "";
    char c;

    while((c = ss.get()) == ' ');
    
    if (c == '-') {
       str += c;
       c = ss.get();
    }
    
    while (c >= '0' && c <= '9') {
        str += c;
        c = ss.get();
    }

    if (str != "") {
        token = atoi(str.c_str());
        isNumber = true;
    }
    
    return true;    
}

TreeNode* deSerializeTree(std::stringstream &ss) 
{
    int value;
    bool isNumber = false;
    
    if (!getNextToken(ss, value, isNumber) || !isNumber)
        return NULL;
    
    TreeNode* root = new TreeNode(value);
    root->left = deSerializeTree(ss);
    root->right = deSerializeTree(ss);
    return root;
}

TreeNode* buildTree(std::string str)
{
    std::stringstream ss;
    ss<<str;
    
    return deSerializeTree(ss);
}

void deleteTree(TreeNode* root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;    
}

void treePreorder(TreeNode* root)
{
    if (!root) {
        std::cout<<"# ";
        return;
    }
    std::cout<<root->val<<" ";
    treePreorder(root->left);
    treePreorder(root->right);
}

void treeInorder(TreeNode* root)
{
    if (!root) {
        std::cout<<"# ";
        return;
    }
    
    treeInorder(root->left);
    std::cout<<root->val<<" ";
    treeInorder(root->right);
    
}

void treePostorder(TreeNode* root)
{
    if (!root) {
        std::cout<<"# ";
        return;
    }
    
    treePostorder(root->left);
    treePostorder(root->right);
    std::cout<<root->val<<" ";
}

bool isLeaf(TreeNode* root) 
{
    if (root && (!root->left && !root->right))
        return true;
    return false;
}
