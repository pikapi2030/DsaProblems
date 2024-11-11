#include <bits/stdc++.h>
using namespace std;

//! assuming counting starting from 0, if starting from 1 just take n+1 instead of n as size

//!T.C O(N)(queue while loop) +O(2e)(internal for loop)  
//!S.C O(3N) ,queue, ans and visted array

vector<int> BFS(int n, vector<int> adj[], int start)
{
    queue<int> qs;
    qs.push(start);
    vector<int> vis(n, 0);
    vector<int> ans;
    vis[start]=1;
    while (!qs.empty())
    {
        int current = qs.front();
        qs.pop();
        ans.push_back(current);
        for (auto it : adj[current])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                qs.push(it);
            }
        }
    }
    return ans;
}
