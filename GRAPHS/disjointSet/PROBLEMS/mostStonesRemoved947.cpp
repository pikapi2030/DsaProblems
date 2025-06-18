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
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point
may have at most one stone.
A stone can be removed if it shares either the same row or the same column as another
stone that has not been removed.
Given an array stones of length n where stones[i] = [xi, yi] represents the location of
the ith stone, return the largest possible number of stones that can be removed.
Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone
still on the plane.
Example 2:
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with
another stone still on the plane.
Example 3:
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
*/

/*approach
we can think of this problem as total stones-total components(derivation below)
lets say we coonect all stones forming m componets,c1,c2..cm
(the condition of joining  a componet is it should share a same col or row with any node
of that component)(wrt question)
assume number of stones in ci component is xi
we know that we can remove xi-1 stones from ci th component(we cannot remove the last stone of each component)
so total stones removed=ans= x1-1 + x2-1+ ... xm-1= (x1+x2+x3...xm)-(1+1+1..m times)=(totalStones)-(total components)

so our main task is to calculate total componets, but issue is we do not have a graph of
stones(to form a dj) but coordinates of it in a 2D plane
we will form a dj in a clever way
maxRow=maxRowCoordinate
maxCol=maxColCoordinate
//!we will use rows and columns as nodes, ith row will be ith node, and ith column will be (maxRow+i+1)th node
if a stone is present at (x,y) we will union(x, maxRow+y+1)
after doing that to all stones, we will check for nodes with parent[i]=i, which will tell the
number of componets, but rows and columns with no stones will also have parent[i]=i,
we have to remove that, so validComponets=if(parent[i]=i&&size[i]>1)
*/
int removeStones(vector<vector<int>> &stones)
{
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    int totalNodes = maxRow + maxCol+2;
    //actually total nodes is maxRow+maxCol+1,but if maxCol,maxRow =0, then total nodes=0+0+2
    disjointSet dj(totalNodes);
    for (auto it : stones)
    {
        int row = it[0]; // ith row=ith node
        int col = it[1]; // ith col=(col+maxRow+1)ith node

        dj.unionBySize(row, col + maxRow + 1);
    }
    int validComp = 0;
    for (int i = 0; i < totalNodes; i++)
    {
        if (dj.parent[i] == i && dj.size[i] > 1) // size >1 means it has participated in a union, thus a valid component for this question
        {
            validComp++;
        }
    }
    return stones.size()-validComp;
}
