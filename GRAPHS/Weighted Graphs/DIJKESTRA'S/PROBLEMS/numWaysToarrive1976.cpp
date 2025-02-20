#include <bits/stdc++.h>
using namespace std;

/*You are in a city that consists of n intersections numbered from 0 to n - 1 with
bi-directional roads between some intersections. The inputs are generated such
that you can reach any intersection from any other intersection and that there
is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei]
means that there is a road between intersections ui and vi that takes timei minutes to travel.
You want to know in how many ways you can travel from intersection 0 to intersection
n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time.
Since the answer may be large, return it modulo 109 + 7.
*/

/*Aproach

we will use dijk, and a ways array, where ways[i]= number of ways to reach ith node taking
min Time
if we reach ith node with min time from jth node, then we will update our ways array like this
ways[i]=ways[i]+ways[j]
if there are 3 ways to reach j(with it's min time) and 5 ways to reeach i with it's min
time(EXCLUDING J) then there are 8 (5+3) WAYS to reach i including j in the path

*/

//! Why not a simple cnt variable counting nuber of ways for dest node?

/*issue with a single var for dest node instead of ways array:-

//!ALL WAYS DISCUSED ARE IN MIN TIME
let say we have 3 node i,j,k, k is our dest node

let's assume there are 3 ways to reach i, 4 ways to reach j
now the i and j nodes are connected to k node by single road

by using a single variable, we would say there are two ways to reach k,
one from i, other from j BUT THE problem is there are multiple ways to reach i and j as well
so //!total number of ways to reach k = total  ways to reach i + total ways to reach j
which can only be done when we keep track of ways to reach of other nodes as well
so we an ARRAY
*/

int dijk(int n, vector<vector<int>> &roads)
{
    long long MOD = 1e9 + 7;

    vector<vector<pair<long long, long long>>> adjL(n);
    vector<long long> ways(n, 0); // ways to reach node is 0 currently
    ways[0] = 1;
    for (auto it : roads)
    {

        adjL[it[0]].push_back({it[1], it[2]}); //{node,time}
        adjL[it[1]].push_back({it[0], it[2]}); // undirected graph
    }

    vector<long long> minTime(n, LONG_LONG_MAX);
    minTime[0] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 0}); //{time,node}
    while (!pq.empty())
    {
        long long node = pq.top().second;
        long long time = pq.top().first;
        pq.pop();
        for (auto it : adjL[node])
        {
            long long adjNode = it.first;
            long long totalTime = it.second + time;

            if (minTime[adjNode] > totalTime)
            {
                ways[adjNode] = (ways[node])%MOD;//for oveflow cases
                minTime[adjNode] = totalTime;
                pq.push({totalTime, adjNode});
            }
            else if (minTime[adjNode] == totalTime)
            {
                ways[adjNode] = (ways[adjNode] + ways[node])%MOD;
            }
        }
    }
    return ways[n - 1];
}

int main()
{
    cout << "main running";
    vector<vector<int>> v = {{1, 0, 10}};
    dijk(2, v);
}
