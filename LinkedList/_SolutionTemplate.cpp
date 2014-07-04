/**
*
*   Description:
*
*   Example:
*
**/

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:

};

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof (A) / sizeof(int);
    Solution sl;

    ListNode* list = buildList(A,  size);
    deleteList(list);
    return 0;
}
