#include <bits/stdc++.h>
using namespace std;

/*
To detect a cycle in a directed graph, we need to maintain a visit status array (visnode).
If we encounter a node that is already part of the current DFS path (visnode[node] = 2), a cycle exists.
If we encounter a node that has already been fully processed in a previous DFS path (visnode[node] = 1),
we skip further exploration from that node.

The visnode array states:
- 0: Node is not visited
- 2: Node is in the current DFS path (path visited)
- 1: Node is fully processed
*/

bool DFSER(vector<vector<int>> &adjL, vector<int> &visnode, int node)
{
    visnode[node] = 2; // Mark the node as currently visiting (part of DFS path)
    for (auto neighbor : adjL[node])
    {
        if (visnode[neighbor] == 0) // Unvisited neighbor
        {
            if (DFSER(adjL, visnode, neighbor) == true)
            {
                return true; // Cycle found
            }
        }
        else if (visnode[neighbor] == 2) // Node is part of the current DFS path
        {
            return true; // Cycle detected
        }
    }
    visnode[node] = 1; // Mark as fully processed
    return false;
}

bool isCycleDirectedDFS(vector<vector<int>> &adjL)
{
    int m = adjL.size();
    vector<int> visnode(m, 0); // Initialize all nodes as not visited (0)

    for (int start = 0; start < m; start++)
    {
        if (visnode[start] == 0) // Start a DFS if the node hasn't been visited
        {
            if (DFSER(adjL, visnode, start) == true)
            {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}
