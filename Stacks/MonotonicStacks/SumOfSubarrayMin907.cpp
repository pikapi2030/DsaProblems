#include <bits/stdc++.h>
using namespace std;

/*
given a vector, return sum of subarrays minimums
*/

/*Brute
generate all subarrays minimus and add them

*/

int BRUTE(vector<int> v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int mins = INT_MAX;

        for (int j = i; j < v.size(); j++)
        {
            mins = min(mins, v[j]);
            sum = sum + mins;
        }
    }
    return sum;
}

/*OPTIMAL(explainations need rework)
we want to avoid generating subarrays for a optimal solution, so instead of generating
subarrays we will simply calcultae the number of contributions a number of the
given vector is going to give in our final sum, then we can simply calculate sum
by multiplying number of contributions of each number by itself,
then we can add all these values to get the final sum.

to calculate number of contrubutions we have to use next smaller and previous greater

let a be the index of element that I am trying to calculate contributions of

let z be next smaller element's index(next smaller to v[a])
let y be previous smaller element's index(previous smaller to v[a])
now ((y-a)+1))*((a-z)+1))= total number of subarrays with v[a] as a min=number of contributions

//!T.C O(5N) S.C O(5N)


*/

vector<int> NextSmallerIndex(vector<int> v)
{
    stack<int> st;
    vector<int> ans(v.size(), -1);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] > v[i]) // storing indexes in stack,one of the NSI OR PSI NEED A STRICT CHECK FOR EDGE CASES(no equal sighn)
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = v.size(); // number of element in right are size-i if no NSE to the right(see line 101)
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> PreviousSmallerIndex(vector<int> v)
{
    stack<int> st;
    vector<int> ans(v.size(), -1);
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] >= v[i]) // storing indexes
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1; // if no PSE then,number of elements in left are i+1(see line 100)
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int OPTIMAL(vector<int> v)
{
    long long modulo=1e9+7;/*this number wiil be used to prevent overflow
    (when result(BIGNUM) increses the size of int(10^9), we can return (BIGNUM % 10^9+7), 
    exmaple ans is 10^9+12, then we have to return 12-7 that is 5
    (this wiil be considered actual answer)(see leetcode quetions)*/


    int sum = 0;
    vector<int> NSI = NextSmallerIndex(v);     // stores next greater indexes wrt to v
    vector<int> PSI = PreviousSmallerIndex(v); // stores PSI wrt v
    for (int i = 0; i < v.size(); i++)
    {

        int Num_Of_Elements_In_left = i - PSI[i];  // it is the count of number of elements in left(including ith) to i
        int Num_Of_Elements_In_right = NSI[i] - i; // it is the count of number of element in right of i including i
        int Num_Of_Subarrays_Contributed = (Num_Of_Elements_In_left) * (Num_Of_Elements_In_right);
        sum = (sum + (Num_Of_Subarrays_Contributed *1LL *v[i])%modulo)%modulo;
        //mod is just to prevent overflow, not related to quetion logic(see leetcode quetions)
    }
    return sum;
}
