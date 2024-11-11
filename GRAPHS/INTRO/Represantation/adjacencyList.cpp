#include <bits/stdc++.h>
using namespace std;
/*
we use vector of array to store a graph
the vector's index represents vertex number and each v[i] stores an array
containing set of vertexes conected by vertex i

S.C O(2*e), e=number of edges
*/

int main()
{
int n,m;
cin>>n,m;
vector<int>adj[n+1];
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);//only if undirected

}
}
//!To store weighted graphs, we simply use vector of array of pairs
