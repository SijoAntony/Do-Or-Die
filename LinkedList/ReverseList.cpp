#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *previous = NULL, *next = NULL;
        
        while(head) {
            next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        
        return previous;
    }
    
    ListNode* reverseRec(ListNode* head) {
        if (!head)
            return head;
        if (!head->next)
            return head;
        
        ListNode* rest = head->next;
        ListNode* newHead = reverseRec(rest);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof (A) / sizeof(int);
    Solution sl;

    ListNode* list = buildList(A,  size);
    cout<<"Before :"; printList(list);
    list = sl.reverse(list);
    list = sl.reverseRec(list);
    cout<<"\nAfter :"; printList(list);

    deleteList(list);
    return 0;
}
