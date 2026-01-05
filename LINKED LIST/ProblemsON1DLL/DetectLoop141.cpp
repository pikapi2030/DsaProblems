#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int data;
    ListNode*next;
};


/*
Detect a loop in LL
*/
/*Mysol
T.C O(N^2)
stores visited adresses in a vector, if found again, loop exists
T.C O(N)
*/
    bool Mysol(ListNode *head) 
    {
       vector<ListNode*>v;
       ListNode *temp=head;
       while(temp!=NULL)
       {
        if(find(v.begin(),v.end(),temp->next)!=v.end())
        {  return true;  }
        v.push_back(temp->next);
        temp=temp->next;

       }
       return false;

    }

/*BRUTE
we solve this using hashmap, we keep node* as a key and bool as the value, if visited
if change value to 1, we also check at every iteration, if address is visited or not

T.C O(2N*Log (n))
S.C O(N)
*/

bool BRUTE(ListNode*head)
{
ListNode*temp=head;
map<ListNode*,int>mp;
while(temp!=NULL)
{
    if(mp.find(temp)!=mp.end())
    {
        return true;
    }
    mp[temp]=1;
    temp=temp->next;

}
return false;
}

/*OPTIMAL
we use tortoise and hare algo, if at any node, our slow and fast pointers meet, then there
must be a loop
if our fast pointer reaches NULL( even number of nodes) or at end of ll (odd number of nodes)
then there is no loop
T.C O(N)
S.C O(1)
*/
bool OPTIMAL(ListNode*head)
{
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;

}


