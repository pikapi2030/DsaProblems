#include <bits/stdc++.h>
using namespace std;
//we use dijkstra's algorithm
//!aplicable only for positive weights
/*
min distance from src to every node in an undirected weighted graph
*/

/*by defult priority queue are max-heap, we have to write a comparator to make it min-heap,
it considers first elemrnt of pair to order
*/ 

/*Aproach
we use a priority queue(min-heap) storing pairs {dist,node}
we initialize an ans array which stores distance from src of ith node 
distance of src from src is 0, so ans[src]=0, all other are infinity
we push {0,src} in our queue and perform a BFS
*/


/*Why Pq?

*/
//! T.C O(ElogV)



vector<int>Dijkestra(vector<vector<pair<int,int>>>adjL,int src)
/*
{
0 {{AdjacentNode,EdgeWt},{},{}}
1 {{AdjacentNode,EdgeWt},{},{}}
2 {{AdjacentNode,EdgeWt},{},{}}
}
*/
{
    int n=adjL.size();
    vector<int>ans(n,INT_MAX);
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>pq;
    /*we first specify the data type of pq, then underlying container of pq, 
    then a compartor to make it min-heap

    */
    ans[src]=0;//!important step

    pq.push({0,src});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        for(auto it:adjL[node])
        {
            int adjNode=it.first;
            int edgeWt=it.second;
            if(ans[adjNode]>edgeWt+dist)
            {
                ans[adjNode]=edgeWt+dist;
                pq.push({edgeWt+dist,adjNode});
            }
        }
    }
    return ans;

}
