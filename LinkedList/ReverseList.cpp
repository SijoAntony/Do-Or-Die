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
            
            if (!next) break;
            
            previous = head;
            head = next;
        }
        
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
    list = sl.reverse(list);
    cout<<"\nAfter :"; printList(list);

    deleteList(list);
    return 0;
}
