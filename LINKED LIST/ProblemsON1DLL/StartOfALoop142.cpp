#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int data;
  ListNode *next;
};

/*
Find start of a lopp if loop is present
*/

/*BRUTE
using hashmaps, we keep track of visited ListNodes, and check if the ListNode is visted again or not
T.C O(N*2LOG N) insert and find function both take logN(may vary for different maps)
S.C O(N)
*/

ListNode *BRUTE(ListNode *head)
{
  map<ListNode *, int> mp;
  ListNode *temp = head;
  while (temp != NULL)
  {
    if (mp.find(temp) != mp.end())
    {
      return temp;
    }
    mp[temp] = 1;
    temp = temp->next;
  }
  return NULL;
}

/*OPTIMAl
we use tortoise and hare to detect if there is a loop
if loop is found,(slow and fast pointers have colided) we point one of the pointers
to head, and other to the collison point(already pointing there) the
move both of them by 1 step, where they will collide is the starting point
(see vid for intution)

T.C O(N+distance b/w loop and starting point)(if no loop then O(n))
*/

ListNode *OPTIMAL(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) // loop detected, move one pointer to head, them move them one step, collison is starting point
    {
      slow = head;
      while (slow != fast)
      {
        slow = slow->next; // BOTH BY ONE STEP
        fast = fast->next;
      }
      return fast; // or slow(both have collided at the starting point)
    }
  }
  return NULL;
}
