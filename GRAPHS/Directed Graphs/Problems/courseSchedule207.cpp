#include <bits/stdc++.h>
using namespace std;
/*
basically we have to tell if there is a cycle or not
we will convert the given prerequisite matrix into a adjList and check if cycle is present
if it is present we return false
*/

vector<vector<int>> prerequisiteToadjlist(vector<vector<int>> pre, int numCourses)
{
    vector<vector<int>> adjL(numCourses);
    for (auto it : pre)
    {
        adjL[it[1]].push_back(it[0]);
    }
    return adjL;
}

bool canFinish(int numCourses, vector<vector<int>> &pre)
{
    vector<vector<int>> adjL = prerequisiteToadjlist(pre, numCourses);
    vector<int> ans;
    int n = numCourses;
    vector<int> inDegree(n, 0);
    // precomputing inDegree of graph
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjL[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> qs;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            qs.push(i);
        }
    }

    while (!qs.empty())
    {

        int node = qs.front();
        qs.pop();
        ans.push_back(node);
        for (auto it : adjL[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                qs.push(it);
            }
        }
    }
    if (ans.size() == n)
    {
        return true;
    }
    return false;
}
