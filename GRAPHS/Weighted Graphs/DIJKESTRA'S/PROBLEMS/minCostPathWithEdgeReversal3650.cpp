#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges)
    {

        vector<vector<pair<int, int>>> adjL(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : edges)
        {
            int parent = it[0];
            int child = it[1];
            int weight = it[2];
            adjL[parent].push_back({child, weight});
            adjL[child].push_back({parent, 2 * weight});
        }
        pq.push({0, 0}); //{ weight,node }
        vector<int> cost(n, 1e9);
        cost[0] = 0;
        while (!pq.empty())
        {
            int curWeight = pq.top().first;
            int parent = pq.top().second;
            pq.pop();
            for (auto it : adjL[parent])
            {
                int goalNode = it.first;
                int costToTraverse = it.second;

                if (costToTraverse + curWeight < cost[goalNode])
                {
                    pq.push({costToTraverse + curWeight, goalNode});
                    cost[goalNode] = costToTraverse + curWeight;
                }
            }
        }
        return (cost[n - 1] == 1e9) ? -1 : cost[n - 1];
    }
};