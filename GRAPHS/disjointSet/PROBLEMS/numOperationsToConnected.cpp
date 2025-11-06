#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

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
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections
forming a network where connections[i] = [ai, bi] represents a connection between computers
ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between
two directly connected computers, and place them between any pair of disconnected computers
to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers
connected. If it is not possible, return -1
*/
/*approach
we know that to  connect n  componets we min need n-1 edges
but we can not create new edges but pick them from within componets, we should pick such edges
that upon removing, does not split the component any more(or disconnect the graph)
those edges are extra edges,
so we need to find the number of extra edges, number of componets
if(extraEdges>=numOfComponets)
{
return numOfComponets-1;
}
else
return -1;
to find extra edges:-
we find it during creation of disjoint set and unioning the nodes connected in input graph,
if we union two nodes which are already part of a component, we got an extra edge

to find num of componets:-
num of ultimate parents will we num of componets(num of{parent[i]=i})
Example 1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
*/
int makeConnected(int n, vector<vector<int>> &g)
{
    int extraEdges = 0;
    int numComponets = 0;
    disjointSet dj(n);
    for (auto it : g)
    {
        int u = it[0];
        int v = it[1];
        if (dj.isConnected(u, v))
        {
            extraEdges++;
        }
        else
        {
            dj.unionBySize(u, v);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dj.parent[i] == i)
        {
            numComponets++;
        }
    }
    if (extraEdges >= numComponets - 1)
    {
        return numComponets - 1;
    }
    return -1;
}
