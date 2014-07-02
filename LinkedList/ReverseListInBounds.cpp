/**
*   Reverse a linked list from position m to n. Do it in-place and in one-pass.
*    
*    For example:
*    Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*    
*    return 1->4->3->2->5->NULL.
*
**/

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *l = &dummy;
        int index = 1;
        
        while (l && index < m) {
            l = l->next;
            index++;
        }
        
        if (!l)
            return dummy.next;
            
        ListNode* start = l;
        l = l->next;
        
        while(l && index < n) {
            ListNode* temp = l->next;
            l->next = l->next->next;
            temp->next = start->next;
            start->next = temp;
            index++;
        }
        
        return dummy.next;
    }
};

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof (A) / sizeof(int);
    Solution sl;

    ListNode* list = buildList(A,  size);
    cout<<"Before :"; printList(list);
    list = sl.reverseBetween(list, 3, 6);
    cout<<"\nAfter :"; printList(list);

    deleteList(list);
    return 0;
}
