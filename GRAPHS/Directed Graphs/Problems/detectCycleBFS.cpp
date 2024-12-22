#include <bits/stdc++.h>
using namespace std;
/*
to detect a cyle in direcetd graph using BFS, we will use khan's algorithm
if our final ordering has size n then there is no cycle
if it's size is less than n than it has a cycle
*/

bool isCycleBFS(vector<vector<int>> adjL)
{
    vector<int> ans;
    int n = adjL.size();
    vector<int> inDegree(n, 0);
    // precomputing inDegree of graph
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjL[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> qs;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            qs.push(i);
        }
    }

    while (!qs.empty())
    {

        int node = qs.front();
        qs.pop();
        ans.push_back(node);
        for(auto it:adjL[node])
        {
            inDegree[it]--;
            if(inDegree[it]==0)
            {
                qs.push(it);
            }
        }

    }
    if(ans.size()==n)
    {
        return true;
    }
    return false;
}
