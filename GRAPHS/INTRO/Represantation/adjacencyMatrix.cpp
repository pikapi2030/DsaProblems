#include <bits/stdc++.h>
using namespace std;
/*
if there N nodes (counting starting from 0) we create a matrix of (N*N)
(if counting starts from 1 we take (n+1)*(n+1)) this matrix has
all cells with 0

if there is an edge between vertex a and vertex b, we will place 1 in cell (a,b) and 
(b,a)(if undirected)

S.C O(n*n)

*/

int main()
{
    int n,m;
    cin>>n,m;
    int adj[n+1][n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u,v;
        adj[u][v]=1;
        adj[v][u]=1;//Assuming undirected graph
    }
}
//!Storing weighted graph
//instead of wrting 1, we write the weight in a,b cell
