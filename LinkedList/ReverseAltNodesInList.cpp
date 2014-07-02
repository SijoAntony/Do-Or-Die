#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseAltNodes(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        dummy->next = head;
        
        while (head) {
            if (!head->next) 
                break;

            tail->next = head->next;
            head->next = head->next->next;
            tail->next->next = head;
            head = head->next;
            tail = tail->next->next;
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
    list = sl.reverseAltNodes(list);
    cout<<"\nAfter :"; printList(list);

    deleteList(list);
    return 0;
}
