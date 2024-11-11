#include <bits/stdc++.h>
using namespace std;

/*
solved using adjacency list
we will use a queue(node to visit,parent )  and a visited array
the reason we taking parent in queue is
!to avoid visiting parent during bfs(but then why taking vis array?)
!we are taking vis array to detect a cycle if node is already visited therfore it has a cycle
*/
//!T.C O(N+2e)(BFS)+O(N)(outer component for loop)  S.C O(N+N) 
bool isCycle(vector<vector<int>> &adjList)
{
    int m = adjList.size(); 
    
    if (m == 0)
    {
        return false;
    }

    vector<int> vis(m, 0);

    for (int start = 0; start < m; start++) //! checking every unvisited nodes to perform BFS in disconnected
    {
        if (vis[start] == 0 && !adjList[start].empty())
        {
            queue<pair<int, int>> qs; //{Node to visit,parent of node }
            qs.push({start, -1});     // parent of starting node is -1
            vis[start] = 1;

            while (!qs.empty())
            {
                int parent = qs.front().second;
                int current = qs.front().first;
                qs.pop();
                for (auto it : adjList[current])
                {
                    if (it != parent)
                    {
                        if (vis[it] == 1)
                        {
                            return true;
                        }
                        qs.push({it, current});
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return false;
}
