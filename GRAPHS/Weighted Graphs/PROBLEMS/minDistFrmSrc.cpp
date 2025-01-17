#include <bits/stdc++.h>
using namespace std;
/*
given a uniformly weighted graph(all edges have equal weights, assuming 1)
find the shortest distance to reach every node from a given source node
*/

vector<int> shortestDistanceBFS(vector<vector<int>>&adjL, int source)
{
    queue<pair<int, int>> qs; //{node,distanceFromSource}
    int n = adjL.size();
    vector<int> ans(n, INT_MAX);
    qs.push({source, 0});
    ans[source] = 0;
    while (!qs.empty())
    {
        int node = qs.front().first;
        int dist = qs.front().second;
        qs.pop();
        for (auto it : adjL[node])
        {
            if (dist+1 < ans[it]) // unvisited or better path
            {
                qs.push({it, dist + 1});
                ans[it] = dist + 1;
            }
        }
    }
    return ans;
}
