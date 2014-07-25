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
    ListNode* nthLastElement(ListNode* head, int k) {
        if (!head)
            return NULL;
            
        ListNode* index = head;     
        while (k-- > 0 && index)
            index = index->next;
            
        if (!index)
            return NULL;
            
        ListNode* node = head;
        while (index) {
            node = node->next;
            index = index->next;
        }
        
        return node;
    }
};

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof (A) / sizeof(int);
    int index = 3;
    Solution sl;

    ListNode* list = buildList(A,  size);
    ListNode* node = sl.nthLastElement(list, index);

    printList(list);
    if (node)
        cout<<"\nNode at "<<index<<" from end is "<<node->val<<endl;
    else
        cout<<"\nInvalid index "<<index<<endl;
    deleteList(list);
    return 0;
}
