#include <bits/stdc++.h>
using namespace std;
/*why a set instead of st?
the point of set is, if I find a node which is already visted with some dist d1,
but I am visitng is with distance d2, where d1>d2 then I will replace that dist with d2
//!!and since node was already visited, it must mean than there is a pair {d1,node} present
//! in the set, now there is no point in keeping this pair in the set as I have a better pair
//!{d2,node}  as d1>d2, so we will erase the redundant pair(can't do it in st)
thus saving us an iteration, but erase function uses log v so the testcase decides
wether it is better to use st or set
*/

vector<int> Dijkestra(vector<vector<pair<int, int>>> adjL, int src)
/*
{
0 {{AdjacentNode,EdgeWt},{},{}}
1 {{AdjacentNode,EdgeWt},{},{}}
2 {{AdjacentNode,EdgeWt},{},{}}
}
*/
{
    int n = adjL.size();
    vector<int> ans(n, INT_MAX);
    set<pair<int, int>> st;

    ans[src] = 0; //! important step

    st.insert({0, src});
    while (!st.empty())
    {
        auto it = *(st.begin()); // basically "it" is first pair of the set
        int node = it.second;
        int dist = it.first;
        st.erase(it); // Erases the "it" pair

        for (auto its : adjL[node])
        {
            int adjNode = its.first;
            int edgeWt = its.second;
            if (ans[adjNode] > edgeWt + dist)
            {
                if (ans[adjNode] != INT_MAX) // visited,Remove the redundant pair
                {
                    st.erase({ans[adjNode], adjNode});
                }
                ans[adjNode] = edgeWt + dist;
                st.insert({edgeWt + dist, adjNode});
            }
        }
    }
    return ans;
}
