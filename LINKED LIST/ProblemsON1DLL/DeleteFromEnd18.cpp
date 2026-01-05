#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
int val;
ListNode*next;

};

/*
Given the head of a linked list, remove the nth node from the end of the list 
and return its head.
*/

/*BRUTE
calculate lenght of LL, then delete the nth node from the start
*/

int LenghtOfLL(ListNode*head)
{
    ListNode* temp=head;//DO NOT TAMPER HEAD
    int cnt=0;
    while(temp)//will stop when temp==NULL
    {
     cnt++;
     temp=temp->next;
    }
    return cnt;

}

ListNode *KthListNodeDelete(ListNode *head, int k)

{
    if (head == NULL)
    {
        return head; // Return if the list is empty
    }

    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next; // Move head to the next ListNode
        delete temp;       // Delete the original head
        return head;       // Return the updated head
    }

    ListNode *temp = head;
    ListNode *prev = NULL;
    int cnt = 0;

    while (temp != NULL && cnt < k)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp != NULL)
    {                            // Ensure k is within the bounds of the list
        prev->next = temp->next; // Skip the k-th ListNode
        delete temp;             // Delete the k-th ListNode
    }

    return head;
}

ListNode * BRUTE(ListNode*head,int n)
{
return KthListNodeDelete(head,LenghtOfLL(head)-n);
}

