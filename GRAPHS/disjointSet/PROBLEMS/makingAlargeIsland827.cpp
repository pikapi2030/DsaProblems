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
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.
Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
*/
