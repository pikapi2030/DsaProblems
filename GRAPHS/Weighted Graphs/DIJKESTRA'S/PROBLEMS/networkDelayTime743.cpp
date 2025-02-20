#include <bits/stdc++.h>
using namespace std;
/*
You are given a network of n nodes, labeled from 1 to n. You are also given times,
a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node,
vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the
n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal,
return -1.
*/

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{

    vector<vector<pair<int, int>>> adjL(n + 1);
    /*
    src0: {dest,time}
    src1 :{dest,time}
    */

    for (auto it : times)
    {
    adjL[it[0]].push_back({it[1], it[2]});
    }
    vector<int> minTime(n + 1, INT_MAX);
    minTime[k] = 0;
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>

        >
        pq; //{time,node}
    pq.push({0, k});
    while (!pq.empty())
    {
        int curTime = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        for (auto it : adjL[curNode])
        {
            int adjNode = it.first;
            int timeTaken = it.second + curTime;
            if (minTime[adjNode] > timeTaken)
            {
                minTime[adjNode] = timeTaken;
                pq.push({timeTaken, adjNode});
            }
        }
    }
    int ans = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        ans = max(minTime[i], ans);
    }
    if(ans==INT_MAX){return -1;}     
    return ans;
}
