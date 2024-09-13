#include <bits/stdc++.h>
using namespace std;

/*
Given two vectors, A and B, A is subset of B
we have to return a vector containing just next greater element(right side)
for each element of A, we have to check next greater in B
returned vector should have answers in same order as order of A
if next greater is not found, set that index to be -1(int the returned vector)

example:-
A = [4, 5, 2, 25]
B = [1, 2, 4, 5, 3, 25,7]

returned vector=[5,25,4,-1]
explanation
- 4 is smaller than 5 so next greater is 5
- 5 is smaller than 25
- 2 is smaller than 4
- 25 has no next greater so -1

*/

/*Brute
we write a function which inputs a number and a vector returns next greater for that
number in the vector, then i reptedly called this function for elements 
in A and return the result in a vector

//! T.C O(N^2)
*/

int NextGreater(int k, vector<int> B)
{
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] == k)
        {
            for (int j = i + 1; j < B.size(); j++)
            {
                if (B[j] > k)
                {
                    return B[j];
                }
            }
            return -1;
        }
    }
}

vector<int> Mysol(vector<int> A, vector<int> B)
{
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        ans.push_back(NextGreater(A[i], B));
    }
    return ans;
}

vector<int>OPTIMAL(vector<int>A,vector<int>B)
{
    stack<int>st;
    unordered_map<int,int>mp;
    vector<int>res;

   
   for(int i=B.size()-1;i>=0;i--)//reverse traversal of B vector
   {
    while(!st.empty()&&st.top()<=B[i])
    {
        st.pop();
    }
    if(st.empty())
    {
        mp[B[i]]=-1;
    }
    else
    {
        mp[B[i]]=st.top();
    }

    st.push(B[i]);

   }
   for(int i=0;i<A.size();i++)
   {
     res.push_back(mp[A[i]]);
   }
   return res;


}

