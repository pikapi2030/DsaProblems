#include <bits/stdc++.h>
using namespace std;
//TODO:Needs work
// check if hamlintonian path exists, if yes, give the path in vector

bool DFS(vector<vector<int>> &adjL, vector<int> &ans, int &cnt, int node, vector<int> &vis)
{
    vis[node]=1; 
    ans[cnt] = node;
    if (cnt == adjL.size() - 1)
    {
        return true;
    }
    cnt++;
    for (auto it : adjL[node])
    {
        if (vis[it] == 0) // unvisited,thus unused and can be used in our cycle
        {
            if (DFS(adjL, ans, cnt, it,vis) == true)
            {
                return true;
            }
        }
    }
    cnt--;         // ham path not possible
    ans[cnt] = -1; // reset the ans vector
    vis[node]=0;
    return false;
}

vector<int> Ham(vector<vector<int>> &adjL)

{
    int count = 0; // counter of how many nodes are in our path, if reaches total nodes,
    // it means ham path detected
    int n = adjL.size();
    vector<int> vis(n, 0);
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) // setting  ith node as a start of ham path
    {
        count=0;
        if(DFS(adjL, ans, count, i, vis)==true)//path found
        {
            break;
        }
    }

    return ans;
}



