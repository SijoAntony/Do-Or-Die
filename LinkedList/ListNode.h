/**
 * Definition for singly-linked list.
 *
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(int A[], int size) 
{
    ListNode *head = NULL;
    for (int i = size - 1; i >= 0; i--) {
        ListNode* newNode = new ListNode(A[i]);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void deleteList(ListNode* head) 
{
    while(head) {
        ListNode* n = head;
        head = head->next;
        delete n;
    }
}

void printList(ListNode* head)
{
    for(ListNode* n = head; n; n = n->next)
        std::cout<<" -> "<<n->val;
}
