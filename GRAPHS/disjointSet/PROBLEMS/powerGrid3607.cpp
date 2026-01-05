#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
// T.C O(4*alpha) which is nearly constant
class disjointSet
{
public:
    vector<int> rank, parent, size;

    disjointSet(int n)
    {
        rank.resize(n + 1, 0); // n+1 works both of 1 based and 0 based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findPar(parent[u]); // with path compression
        /*when we find the ultimate parent, we perform path compression,
        parent[u]= ultimate parent found by the function =findpar(parent[u])
        (done while returning)
        */
    }

    void unionByRank(int u, int v)
    {
        int pu = findPar(u); // ult par of u
        int pv = findPar(v); // ult par of v
        if (pu == pv)        // already connected as ult parents are same
        {
            return;
        }
        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else // rank[pu]==rank[pv]
        {
            parent[pu] = pv; // can also connect other way does not matter
            rank[pv]++;      // when  connecting same rank, rank increases
        }
    }
    void unionBySize(int u, int v)
    {
        int pu = findPar(u); // ult par of u
        int pv = findPar(v); // ult par of v
        if (pu == pv)        // already connected as ult parents are same
        {
            return;
        }
        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else //(size[pv] >= size[pu])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    bool isConnected(int u, int v)
    {
        return findPar(u) == findPar(v);
    }
};

/*
You are given an integer c representing c power stations, each with a unique identifier
id from 1 to c (1‑based indexing).
These stations are interconnected via n bidirectional cables, represented by a 2D array
connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.
Initially, all stations are online (operational).
You are also given a 2D array queries, where each query is one of the following two types:

    [1, x]: A maintenance check is requested for station x. If station x is online,
    it resolves the check by itself. If station x is offline, the check is resolved by
    the operational station with the smallest id in the same power grid as x. If
    no operational station exists in that grid, return -1.

    [2, x]: Station x goes offline (i.e., it becomes non-operational).

Return an array of integers representing the results of each query of type [1, x] in the
order they appear.
Note: The power grid preserves its structure; an offline (non‑operational) node remains part of
its grid and taking it offline does not alter connectivity.
*/

/*approach
used DSU to keep track of nodes belonging to same components
used map of sorted sets, where each root(true parent) is given a sorted set
whenever a node goes offline, we remove it from our sorted set of respective component it 
belong to, so our sorted set only keeps online nodes
whenever min node is asked, it is first node in our sorted set
int firstElementInASortedSet = *set.begin()
*/

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        disjointSet dj(c);
        vector<bool> isOnline(c + 1, 1);
        vector<int> ans;

        for (auto it : connections)
        {
            dj.unionByRank(it[0], it[1]);
        }

        unordered_map<int, set<int>> mp; // each component will have it's own sorted set to determine min id
        for (int i = 1; i <= c; i++)
        {
            if (dj.findPar(i) == i) // true parent(root of component)
            {
                // assing a sorted set to it
                mp[i] = {};
            }
        }
        for (int i = 1; i <= c; i++)
        {
            mp[dj.findPar(i)].insert(i); // inserting nodes to there belonging sets
        }

        for (auto it : queries)
        {
            int queryType = it[0];
            int node = it[1];
            int parent = dj.findPar(node);
            if (queryType == 1)
            {
                if (isOnline[node])
                {
                    ans.push_back(node);
                }
                else
                {
                    mp[parent].empty() ? ans.push_back(-1) : ans.push_back(*mp[parent].begin());
                }
            }
            if (queryType == 2)
            {
                isOnline[node] = 0;
                mp[parent].erase(node);
            }
        }
        return ans;
    }
};
