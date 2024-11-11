#include <bits/stdc++.h>
using namespace std;

bool isCycleDFSER(vector<vector<int>> &adjList, vector<int> &vis, int node, int parent)
{
    vis[node] = 1;
    for (auto it : adjList[node])
    {
        if (it != parent)
        {
            if (vis[it] == 1)
            {
                return true;
            }
            else if (isCycleDFSER(adjList, vis, it, node) == true)
            {
                return true;
            }
        }
    }
    return false;
}
bool iscycleDFS(vector<vector<int>> &adjL)
{
    int m = adjL.size();
    vector<int> vis(m, 0);
    for (int i = 0; i < m; i++)
    {
        if (vis[i] == 0)
        {
            if (isCycleDFSER(adjL, vis, i, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}