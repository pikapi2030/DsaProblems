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
You have a 2D grid of ‘N’ rows and ‘M’ columns which are initially filled with water.
You are given ‘Q’ queries each consisting of two integers ‘X’ and ‘Y’ and in each query
operation, you have to turn the water at position (‘X’, ‘Y’) into a land. You are supposed
to find the number of islands in the grid after each query.
An island is a group of lands surrounded by water horizontally, vertically, or diagonally.
*/

/*aproach
N*M grid
we will consider every point in a grid as a node,to convert (row,col) into nodes,
nodeNumber= (row*m+col),m=size of grid column wise
numIsland=0
if we get a query of (x,y) we will assume it is and individual island and do a numIsland++
then we check if it is adjacent to any other island, if it is do a numIsland--
but if the ultParent is differnet, then do a union

example:-  * is the place where new island will come
numIslandBeforeQuery=1
now we do a numIsland++, so numIsland=2
now we check the surrounding of *, on left of *, we find an island with diff ultParent
so we do a numIsland-- and union them, now on top, * has same ult parent as top so
we do nothing, similary for all other sides

0 1 1 1
0 1 * 1
0 0 0 0

*/

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    disjointSet dj(n * m);
    vector<int> ans;
    int numIsland = 0;
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    for (auto it : q)
    {
        int row = it[0];
        int col = it[1];
        int node = row * m + col;
        if (vis[row][col] == 1)
        {
            continue;
        }
        vis[row][col] = 1;
        numIsland++;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            int nNode = nrow * m + ncol;
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 1)
            {
                if (!dj.isConnected(node, nNode))
                {
                    numIsland--;
                    dj.unionBySize(node, nNode);
                }
            }
        }
        ans.push_back(numIsland);
    }
    return ans;
}
