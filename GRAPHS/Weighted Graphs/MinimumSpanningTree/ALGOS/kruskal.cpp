#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> rank, parent, size;

public:
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

/*approach
we will be using a disjoint set
step1: sort all edges according to edge wt
step2: create a disjoint set of n size
step3: check if node and adjNode are part of same component,if not join them and add them to mst
step 4: return ans
*/
int kruskal(vector<vector<int>> &edges) //{{node,adjnode,wt}}
{
    int sum = 0;
    int n = edges.size();
    disjointSet dj(n);
    vector<pair<int, pair<int, int>>> g; //{{wt,{node,adjnode}}}
    for (auto it : edges)
    {
        int wt = it[2];
        int node = it[0];
        int adjnode = it[1];
        g.push_back({wt, {node, adjnode}});
    }
    sort(g.begin(), g.end());
    for (auto it : g)
    {
        int wt = it.first;
        int node = it.second.first;
        int adjnode = it.second.second;
        if (!dj.isConnected(node, adjnode))
        {
            sum += wt;
            dj.unionBySize(node, adjnode);
        }
    }
    return sum;
}
