#include <bits/stdc++.h>
using namespace std;

void DFSER(int node, stack<int> st, vector<int> &vis, vector<vector<pair<int, int>>> adjL)
{
    vis[node] = 1;
    for (auto it : adjL[node])
    {
        int AdjNode = it.first;
        if (!vis[AdjNode])
        {
            DFSER(AdjNode, st, vis, adjL);
        }
    }
    st.push(node);
}

stack<int> TopoDFS(vector<vector<pair<int, int>>> &adjL) // weighted DAG
/*
{
1   {{adjNODE,EdgeWT},{adjNODE,EdgeWT},{adjNODE,EdgeWT}}
2   {{adjNODE,EdgeWT},{adjNODE,EdgeWT}}
3   {{adjNODE,EdgeWT},{adjNODE,EdgeWT},{adjNODE,EdgeWT},{adjNODE,EdgeWT}}
}
*/
{
    stack<int> st;
    int n = adjL.size();
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFSER(i, st, vis, adjL);
        }
    }
    return st;
}

/*
given a DAG(directed acyclic graph), with non-uniform weights
return an array having min distance from source to every ith node
*/

/*aproach
step 1:- perform a topo sort, and use the stack of topo sort
(topo sort done by DFS as we are sure we have DAG)

step 2:- create a dist array(ans) initialised with infinite
distance at every index,mark dist[source]=0

step 3:-(called relaxation of edges)
got to top of the stack pop nodes until top is source node,
(as any node before src node in topo sort is not reachable(DAG))
now check adjacent nodes of top(src) and update the distance is ans array
by doing this:-
dist[adjacent node]=dist[src]+edge wt(b/w src and adj node)//!more general form below
now pop src and got to next top,
update distance by doing this :-

dist[ node adjacent to top node ]=dis[top]+edgeWT(b/w top and adjcent node)
return the answer when stack is empty
*/

vector<int> EdgeRelax(int src, vector<vector<pair<int, int>>> adjL)
{
    int n = adjL.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    stack<int> topoSt = TopoDFS(adjL);

    while (topoSt.top() != src)
    {
        topoSt.pop();
    }
    while (!topoSt.empty())
    {
        int topNode = topoSt.top();
        topoSt.pop();
        for (auto it : adjL[topNode])
        {
            int adjNode = it.first;
            int edgeWT = it.second;
            int distanceFromsrc = dist[topNode] + edgeWT;
            if (dist[adjNode] > distanceFromsrc)
            {
                dist[adjNode] = distanceFromsrc;
            }
        }
    }
    return dist;
}
