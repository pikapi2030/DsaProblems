#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(nullptr) {}  // Constructor for ListNode
};

/*
Given the head of a singly linked list, sort the list using insertion sort,
and return the sorted list's head.
*/

ListNode* InsertionSortOnLL(ListNode* head)
{
    ListNode* Dummy = new ListNode(0);  // Dummy node to help with the sorted part
    ListNode* current = head;  // Pointer to iterate through the original list
    
    while (current)
    {
        ListNode* nextNode = current->next;  // Save the next node
        
        // Find the correct spot to insert the current node in the sorted part
        ListNode* temp = Dummy;  
        
        // Traverse the sorted part of the list to find the correct position
        while (temp->next && temp->next->val < current->val)
        {
            temp = temp->next;
        }
        
        // Insert the current node in the sorted part
        current->next = temp->next;
        temp->next = current;
        
        // Move to the next node in the original list
        current = nextNode;
    }
    
    return Dummy->next;  // Return the head of the sorted list
}

// Helper function to print the linked list
void printList(ListNode* head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a simple linked list: 4 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << "Original list: ";
    printList(head);

    head = InsertionSortOnLL(head);  // Perform insertion sort

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
