#include <bits/stdc++.h>
using namespace std;
/*aproach
we use stack(to store our final answer in reverse), vis aray
we do basic DFS and mark vis
after dfs of node is complete we put it in stack
extract our answer from stack(reverse the stack)
*/

/*
!problems:- this code cannot detect if our graph has cycle or not,
!so if given a graph with cycle it will return an impossible ordering.
*/

void DFSER(vector<vector<int>> &adjL, vector<int> &vis, stack<int> &st, int node)
{
    vis[node] = 1;
    for (auto it : adjL[node])
    {
        if (!vis[it])
        {
            DFSER(adjL, vis, st, it);
        }
    }
    st.push(node);
}

vector<int> TopoDFS(vector<vector<int>> &adjL)
{
    vector<int> ans;
    stack<int> st;
    int n = adjL.size();

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFSER(adjL, vis, st, i);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());

        st.pop();
    }
    return ans;
}
