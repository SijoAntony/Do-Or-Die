/**
*   Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. 
*   Print all sums through different vertical lines.
*
*   Examples:
*
*         1
*       /   \
*      2     3
*     / \   / \
*    4   5 6   7
*
*   The tree has 5 vertical lines
*
*   Vertical-Line-1 has only one node 4 => vertical sum is 4
*   Vertical-Line-2: has only one node 2=> vertical sum is 2
*   Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
*   Vertical-Line-4: has only one node 3 => vertical sum is 3
*   Vertical-Line-5: has only one node 7 => vertical sum is 7
*
*   So expected output is 4, 2, 12, 3 and 7
*
*
**/

#include <iostream>
#include <map>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void printVericalSum(TreeNode *root) {
        map<int, int> sums;

        printVericalSum(root, 0, sums);

        for (map<int, int>::iterator it = sums.begin(); it != sums.end(); ++it)
            cout<<it->second<<" ";
        cout<<endl;
    }

    void printVericalSum(TreeNode *root, int horzDist, map<int, int>& sums) {
        if (!root)
            return;
            
        int prevSums = sums.find(horzDist) == sums.end() ? 0 : sums[horzDist];
        sums[horzDist] = prevSums + root->val;
        printVericalSum(root->left, horzDist - 1, sums);
        printVericalSum(root->right, horzDist + 1, sums);
    }    
};

int main()
{
    string str = "1 2 4 # # 5 # # 3 6 # # 7 # #";
    
    TreeNode* root = buildTree(str);

    Solution sl;
    sl.printVericalSum(root);

    deleteTree(root);
    
    return 0;
}
