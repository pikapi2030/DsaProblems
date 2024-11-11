#include <bits/stdc++.h>
using namespace std;
/*we have to tell if a graph is bipartite or not
a bipartite graph is a graph where we can color the nodes using two colors and no adjacent
nodes have the same color
every graph without loop is bipartite
every graph with loop of even lengths is bipartite
graph with loop of odd length is not bipartite

*/

/*aproach

*/

bool DFSER(vector<vector<int>> &adjL, vector<int> &visColor, int node, int prevColor)
{
    if (prevColor == 1)
    {
        visColor[node] = 2;
    }
    else if(prevColor==2)
    {
        visColor[node] = 1;
    }
    for(auto it:adjL[node])
    {
     if(visColor[it]==0)
     {
       return DFSER(adjL,visColor,it,visColor[node]);
     }
     else if(visColor[it]==visColor[node])
     {
        return false;
     } 
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int m=graph.size();
    vector<int>visColor(m,0);//! 0 means uncolored/unvisited, 1 means color:-1, 2 means color:- 2  
    for(int start=0;start<m;start++)
    {
        if(visColor[start]==0)
        {
            //starting from color 1

            if(DFSER(graph,visColor,start,1)==false)
            {
                return false;
            }
        }
    }
    return true;

}