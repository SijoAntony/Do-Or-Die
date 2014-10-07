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
#include "TreeNode.h"

using namespace std;

int depth(vector<int> &parents, int node, vector<int>& depths)
{
    if(depths[node])
        return depths[node];
        
    if(parents[node] == -1)
        depths[node] = 1;
    else
        depths[node] =  depth(parents, parents[node], depths) + 1;
    return depths[node];   
}

int height(vector<int> &parents)
{
    int height = 0;
    vector<int> depths(parents.size(), 0);
    
    for (int i = 0; i < parents.size(); i++) {
        int d = depth(parents, i, depths);
        height = max(height, d);
    }
    
    return height;
}


int main()
{
    //vector<int> parents = {1, 5, 5, 2, 2, -1, 3};
    //vector<int> parents = {-1, 0, 0, 1, 1, 3, 5};
    vector<int> parents = {-1, 0, 1, 2, 3, 4, 5};

    cout << "Height is " << height(parents);
    return 0;    
}
