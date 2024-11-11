#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixToListUNDIRECTED(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size();
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    return adjList;
}

/*Undirected Graph
There are n cities. Some of them are connected, while some are not. If city a is
connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

/*Aproach
we will convert the given adj matrix into adj list
then we will do DFS traversal, the number of time DFS traversal will be called is
our number of provincies
*/

/*
!This modified func visits only one province, 
!so we have to call it in a loop using vis array condition
!number of times this is called(not recursively, but by loop in if condition ) is the number 
!of provinces
*/
//! T.C O(N)(vis loop in main function) + O(N+2e)(DFS travesal)  
//!t.c of matrix to list is not counted  S.C O(N)(vis array)+O(N)(list)+O(N)(recursion stack space)

void modifiedDFS(vector<vector<int>> adjList, vector<int> &vis, int start)
{

    vis[start] = 1;
    for (auto it : adjList[start])
    {
        if (vis[it] == 0)
        {
            modifiedDFS(adjList, vis, it);
        }
    }
    return;
}

int numberOfProvinces(vector<vector<int>> adjMatrix)
{

    int provinces = 0;
    vector<vector<int>> adjList = matrixToListUNDIRECTED(adjMatrix);
    int n = adjList.size();
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            provinces++;
            modifiedDFS(adjList, vis, i);
        }
    }
    return provinces;
}
