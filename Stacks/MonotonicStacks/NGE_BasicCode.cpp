#include <bits/stdc++.h>
using namespace std;
/*
return a vector with where ans[i]=next greater element to v[i]
example:- v={6,0,8,1,3}
ans={8,8,-1,3,-1}
*/
//T.C O(N)  S.C O(N)

vector<int> NGE(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(v[n - 1]);
    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && v[i] >= st.top())
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
        st.push(v[i]);
    }
    return ans;
}
// cleaner code
vector<int> nge(vector<int> v)
{
    int n = v.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[i] >= st.top())
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(v[i]);
    }
    return ans;
}
