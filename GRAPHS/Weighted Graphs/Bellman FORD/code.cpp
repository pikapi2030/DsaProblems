#include <bits/stdc++.h>
using namespace std;

vector<int> BellManFord(int n, vector<vector<int>> &edges, int source)
{
    vector<int> minDist(n, 1e8);
    minDist[source]=0;
    for (int i = 0; i < n-1; i++) // relaxation loop
    {
        for (auto it : edges)
        {
            int src = it[0];
            int dst = it[1];
            int wt = it[2];

            if (minDist[src] != 1e8 && minDist[src] + wt < minDist[dst])
            {
                minDist[dst] = wt + minDist[src];
            }
        }
    }
    //! checking for Nth time, if minDist gets updates, it means there is an Negative cycle
    for (auto it : edges)
    {
        int src = it[0];
        int dst = it[1];
        int wt = it[2];

        if (minDist[dst] != 1e8 && minDist[src] + wt < minDist[dst])
        {
            //! NEGATIVE CYCLE PRESENT(no actuall answer)
            return {-1};
        }
    }
    return minDist;
}