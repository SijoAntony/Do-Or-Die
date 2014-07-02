/**
* Given a linked list, write a function to reverse every alternate k nodes 
* (where k is an input to the function) in an efficient way.
*
* Example:
* Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
* Output:   3->2->1->4->5->6->9->8->7->NULL. 
*
**/

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseAltKNodes(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
            
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* p1 = head, *p2 = head;
        
        while (1) {
            int index = 0;

            for(; p2 && index < k; p2= p2->next, index++);

            if (!p2 && index < k) {
                tail->next = p1;
                break;
            }
            ListNode* curTail = tail;
            tail = p1;
            while (p1 != p2) {
                ListNode* temp = p1;
                p1 = p1->next;
                temp->next = curTail->next;
                curTail->next = temp;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof (A) / sizeof(int);
    Solution sl;

    ListNode* list = buildList(A,  size);
    cout<<"Before :"; printList(list);
    list = sl.reverseAltKNodes(list, 3);
    cout<<"\nAfter :"; printList(list);

    deleteList(list);
    return 0;
}
