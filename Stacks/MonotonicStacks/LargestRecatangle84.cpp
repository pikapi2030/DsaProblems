#include <bits/stdc++.h>
using namespace std;
/*
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

vector<int> PreviousSmallerIndexes(vector<int> v)
{
    int n = v.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; n > i; i++)
    {
        while (!st.empty() && v[i] < v[st.top()])
        {
            st.pop();
        }
        if (st.empty()) // no prev smaller
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

vector<int> NextSmallerIndexes(vector<int> v)
{
    stack<int> st;
    int n = v.size();
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] >= v[i])//EQUal to for edge casw [1,1]
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

int Mysol(vector<int> v)
{
    int n = v.size();
    vector<int> PREV = PreviousSmallerIndexes(v);
    vector<int> NEXT = NextSmallerIndexes(v);
    int MaxArea=0;
    for(int i=0;i<n;i++)
    {
        int Leftwidth=i-PREV[i];
        int RightWidth=NEXT[i]-i;
        int area=v[i]*(Leftwidth+RightWidth-1);
        MaxArea=max(MaxArea,area);
    }
    return MaxArea;

}
