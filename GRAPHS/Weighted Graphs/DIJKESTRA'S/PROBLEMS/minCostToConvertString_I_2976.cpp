#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> minCostFromAnyToAny(vector<vector<pair<int, int>>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> costFromAnyToAny(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
        {
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i}); // cost,node
            while (!pq.empty())
            {
                int costTillNow = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if (costTillNow > dist[node])
                {
                    continue;
                }

                for (auto it : graph[node])
                {
                    int costToTravel = it.first;
                    int goalNode = it.second;
                    if (dist[goalNode] > costToTravel + costTillNow)
                    {
                        dist[goalNode] = costToTravel + costTillNow;
                        pq.push({costToTravel + costTillNow, goalNode});
                    }
                }
            }
            costFromAnyToAny[i] = dist;
        }
        return costFromAnyToAny;
    }

    vector<vector<pair<int, int>>> buildGraph(vector<char> &org, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<pair<int, int>>> graph(26);
        int n = org.size();
        for (int i = 0; i < n; i++)
        {
            graph[org[i] - 'a'].push_back({cost[i], changed[i] - 'a'});
        }
        return graph;
    }
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        long long ans = 0;
        int n = source.size();
        vector<vector<pair<int, int>>> graph = buildGraph(original, changed, cost);
        vector<vector<int>> costFromAnyToAny = minCostFromAnyToAny(graph);

        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                if (costFromAnyToAny[source[i] - 'a'][target[i] - 'a'] == 1e9)
                {
                    return -1;
                }
                ans += costFromAnyToAny[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};