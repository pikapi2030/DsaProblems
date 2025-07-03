#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j],
where 0 <= i <= j < n.
Example 1:
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
!!all nums within 31 bit range
*/

/*
approach:-
a^b is max when a and b are inverse of each other(bits flipped)
we will store all numbers in a trie in binary form(MSB first(left side)),
now lets say we have a number x and want to find largest xor possible with x and nums[i],
we will try to find the inverse
of x in our trie
assume x=  MSB 0 1 0 0 1 LSB
so we try to find if our trie has 1(inverse of 0) if yes then when put a 1 at that position
in our ans(in binary) if not we just move ahead
*/

class Node
{
public:
    Node *link[2]; // stores 0 or 1
    Node()
    {
        link[0] = NULL;
        link[1] = NULL;
    }
    bool isPresent(int bit)
    {
        return link[bit] != NULL; // bit not NULL there it is there
    }
    void put(int bitToPut, Node *node) // will pass a new node
    {
        link[bitToPut] = node;
    }
    Node *getAddress(int bit)
    {
        return link[bit];
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node;
    }

    void insert(int num)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int ithBit = (num >> i) & 1;
            if (!temp->isPresent(ithBit))
            {
                temp->put(ithBit, new Node);
            }
            temp = temp->getAddress(ithBit);
        }
    }
    int maxXor(int num)
    {
        int ans = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int ithBit = (num >> i) & 1;
            int inverseBit = 1 - ithBit;
            if (temp->isPresent(inverseBit))
            {
                // set ith bit of ans=1;
                ans = (1 << i) | ans;
                temp = temp->getAddress(inverseBit);
            }
            else
            {
                temp = temp->getAddress(ithBit); // since inverse bit is not pressent, ith bit will be present
            }
        }
        return ans;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie tr;
    for (auto it : nums)
    {
        tr.insert(it);
    }
    int ans = 0;
    for (auto it : nums)
    {
        ans = max(tr.maxXor(it), ans);
    }
    return ans;
}
int findMaximumXOR(vector<int> &nums)
{
    Trie tr;
    for (auto it : nums)
    {
        tr.insert(it);
    }
    int ans = 0;
    for (auto it : nums)
    {
        ans = max(tr.maxXor(it), ans);
    }
    return ans;
}
