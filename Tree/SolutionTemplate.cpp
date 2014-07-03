/**
*
**/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
};

int main()
{
    string str = "5 3 2 1 # # # 4 # # 7 6 # # 8 # #";
    
    TreeNode* root = buildTree(str);
    Solution sl;

    deleteTree(root);
    
    return 0;
}
