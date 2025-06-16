#include <bits/stdc++.h>
using namespace std;
/*aproach
we will use largest rec in histogram
we can observe that this question is largestRecinHisto at every row, we just have to build the
histoGram for every row and calculate the area at every row and maximise it
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
        while (!st.empty() && v[st.top()] >= v[i]) // EQUal to for edge casw [1,1]
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

int largestRecInHisto(vector<int> v)
{
    int n = v.size();
    vector<int> PREV = PreviousSmallerIndexes(v);
    vector<int> NEXT = NextSmallerIndexes(v);
    int MaxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int Leftwidth = i - PREV[i];
        int RightWidth = NEXT[i] - i;
        int area = v[i] * (Leftwidth + RightWidth - 1); // we can also do next[i]-prev[i]-1
        MaxArea = max(MaxArea, area);
    }
    return MaxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxArea = 0;
    vector<int> histo(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                histo[j]++;
            }
            else
            {
                histo[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRecInHisto(histo));
    }
    return maxArea;
}

//!best aproach:- there is a better code of largest rec in histo which does not use any extra vectors
