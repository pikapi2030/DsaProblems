#include <bits/stdc++.h>
using namespace std;
//TODO Code Not Correct
/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*Aproach
we will calculate sum of min of sub array and sum of max of subarray then subtract both of them
it will be our answer
*/

vector<int> NextGreaterIndex(vector<int> v)
{
    int n = v.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = v.size();
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> PreviousGreaterIndex(vector<int> v)
{
    int n = v.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[i] >= v[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> NextSmallerIndex(vector<int> v)
{
    int n = v.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] > v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = v.size();
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
    int n = v.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int Mysol(vector<int>v)
{
    int n=v.size();
    int SumOfMin=0;
    int SumOfMax=0;
    vector<int>PREVsmall=PreviousSmallerIndex(v);
    vector<int>PREVgreat=PreviousGreaterIndex(v);
    vector<int>NEXTsmall=NextSmallerIndex(v);
    vector<int>NEXTgreat=NextGreaterIndex(v);
    for(int i=0;i<n;i++)
    {
     int SmallLeftCount=i-PREVsmall[i];
     int SmallRightCount=NEXTsmall[i]-i;
     int GreatLeftcount=i-PREVgreat[i];
     int GreatRightCount=NEXTgreat[i]-i;
     int NumOfSubarraysInMin=(SmallLeftCount*SmallRightCount);
     int NumOfSubarraysInMax=(GreatLeftcount*GreatRightCount);

     SumOfMin=SumOfMin+v[i]*NumOfSubarraysInMin;
     SumOfMax=SumOfMax+v[i]*NumOfSubarraysInMax;
    
    }
    return SumOfMax-SumOfMin;
}

