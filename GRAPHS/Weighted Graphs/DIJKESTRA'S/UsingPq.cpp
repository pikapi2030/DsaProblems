#include <bits/stdc++.h>
using namespace std;
//! E LOG(V)

/*Why PQ and not Queue?

Pq prevents many redundant pairs,
for example assume we can reach node N1 with dist D1 and D2, D2>D1
so we have two pairs {D1,N1} and {D2,N1},
and we can reach N2 from N1 in dist K

In case of pq, {D1,N1} will be processed first and all possible path from 
N1 will be calculated, so new pair {D1+k,N2} will be added 
then we will process {D2,N1} but since all possible paths
are already calculated, and the pair {D2+K,N2}(REDUNDANT PAIR)
will never be added as D2+K>D1+k
Now if we use normal queue, we might end up processing {D2,N1} first,
which will lead to addition of {D2+K,N2}(REDUNDANT PAIR), we know that
there is a better way but since there no ordering of pair we might end up processing 
random pairs which will generate redundant pairs

*/


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
