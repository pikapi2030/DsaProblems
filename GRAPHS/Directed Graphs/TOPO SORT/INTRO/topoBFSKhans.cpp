#include <bits/stdc++.h>
using namespace std;
//! Kahn's algo
/*
we use a queue, a in-degree array(it stores how many in-edges our node has)
!in-degree array is pre-computed
we check which node has 0 in-degree, this came be first in our ordering as there is no
node before that, we put it into queue and perfrom BFS, during traversal if go to a neighbouring
node, we reduce it's indegree by one, if neighbour's indegree becomes zero(after updation)
then we push it into the queue(as we are sure that no node is before that,
as we have taken all nodes which were before our neighbour into ordering already)
*/
//! If our ans vector has size less than n than aour graph has cycle

vector<int> TopoBFS(vector<vector<int>> adjL)
{
    // precomputing in-degree array
    int n = adjL.size();
    vector<int> ans;
    vector<int> inDegree(n, 0);
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
        if (inDegree[i] == 0) // we are sure that no one comes before i
        {
            qs.push(i);
        }
    }
    while (!qs.empty())
    {
        int node = qs.front();
        qs.pop();
        ans.push_back(node);
        for (auto it : adjL[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                qs.push(it);
            }
        }
    }
    if (ans.size() == n)
    {
        return ans;
    }
    else
    {
        //cycle detected, order not possible
        vector<int>v(n,-1);
        return v;
    }
}
