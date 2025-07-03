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

/*approach
connect all 1's
at every 0, check all 4 directions, if 1 is neghbour, add it's ultParent to a set(set to avoid same ult parents)
after checking all 4, add size of componets whoose parents are present in set,
also add +1 to the final sum ( taking account of 0 chaning to 1(not actually changing))
maximise this sum
*/

int largestIsland(vector<vector<int>> &grid) // n*n
{
    int n = grid.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += grid[i][j];
        }
    }
    if (sum == n * n) // if all ones
    {
        return sum;
    }

    disjointSet dj(n * n);
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};
    // connect 1 components to each other
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
            {
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (ncol >= 0 && nrow >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 1)
                {
                    int node = row * n + col;
                    int nNode = nrow * n + ncol;
                    dj.unionBySize(node, nNode);
                }
            }
        }
    }
    // brute forcing every zero cell(we are not actually chaning a 0->1, but adding +1 to the sum)
    /*
    if we are at zero cell, we check the neigbours of it, if they are 1 we add the node's parent
    to out set( set to avoid adding two same  ultimate parents)
    after checking all four, we add the size of components whoose parent are in our set
    we also add +1 to final sum(the 0 will also turn into 1(virtually no actually))
    we maximise this sum
    */
    int maxi = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
            {
                continue;
            }
            set<int> st;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (ncol >= 0 && nrow >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 1)
                {
                    int nNode = nrow * n + ncol;
                    st.insert(dj.findPar(nNode));
                }
            }
            int sum = 0;
            for (auto it : st)
            {
                sum += dj.size[it];
            }
            maxi = max(sum + 1, maxi);
        }
    }
    return maxi;
    
}