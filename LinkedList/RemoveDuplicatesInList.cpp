/**
*
*   Description: 
*           Write code to remove duplicates from an unsorted linked list.
*
*   Example:
*           Input  1->1->4->1->4->6->7->7
*           Output 1->4->6->7
*
**/


#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    void removeDuplicates(ListNode *head) {
        if (!head)
            return;
            
        ListNode* current = head;
        ListNode* next = head->next;
        
        while(next) {
            ListNode* index = head;
            while(index != next) {
                if (next->val == index->val) {
                    ListNode* temp = next;
                    next = next->next;
                    current->next = next;
                    delete temp;
                    break;
                }
                index = index->next;
            }
            if (index == next) {
                current = next;
                next = next->next;
            }
        }
        
        current->next= NULL;
    }

};

int main()
{
    int A[] = {1, 1, 4, 1, 4, 6, 8, 8};
    int size = sizeof (A) / sizeof(int);
    Solution sl;

    ListNode* list = buildList(A,  size);
    printList(list); cout<<endl;
    sl.removeDuplicates(list);
    printList(list);
    deleteList(list);
    return 0;
}
