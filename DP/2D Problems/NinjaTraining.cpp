#include <bits/stdc++.h>
using namespace std;
/*
Geek is going for a training program for n days. He can perform any of these activities:
Running, Fighting, and Learning Practice. Each activity has some point on each day.
As Geek wants to improve all his skills, he can't do the same activity on two consecutive days.
Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent
the merit points for Running, Fighting, and Learning on the i-th day,
determine the maximum total merit points Geek can achieve .
*/

// Brute aproach T.C O(3^n) S.C O(N)
int BRUTE(vector<vector<int>> &v, int day, int PrevTask)
{
    // helper(v,a,b)  return maximum points till day a, if task b was done on day a+1
    int n = v.size();
    if (day == 0)
    {
        int maxi = 0; // represent the task with highest merit on last column, which was not done on previous day(2nd last column)
        for (int i = 0; i < 3; i++)
        {
            if (PrevTask != i)
            {
                maxi = max(v[day][i], maxi);
            }
        }
        return maxi;
    }
    int TotalPoints = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (PrevTask != i)
        {
            int tp = v[day][i] + BRUTE(v, day - 1, i);
            TotalPoints = max(TotalPoints, tp);
        }
    }
    return TotalPoints; // maximised
}

int maximumPoints(vector<vector<int>> &v)
{
    int n = v.size();
    // 3 measn no task was performed
    return BRUTE(v, n - 1, 3); // here day is n-1, and on ((n-1)+1)th day no task can be performed so 3
}

// Memoisation:- we will use a dp matrix of size N*4, 4 is number of columns represeting las task(0,1,2,3)
int memo(vector<vector<int>> &v, int day, int PrevTask, vector<vector<int>> &dp)
{
    // helper(v,a,b)  return maximum points till day a, if task b was done on day a+1
    int n = v.size();

    if (day == 0)
    {
        int maxi = 0; // represent the task with highest merit on last column, which was not done on previous day(2nd last column)
        for (int i = 0; i < 3; i++)
        {
            if (PrevTask != i)
            {
                maxi = max(v[day][i], maxi);
            }
        }
        return dp[day][PrevTask] = maxi;
    }
    if (dp[day][PrevTask] != -1)
    {
        return dp[day][PrevTask];
    }

    int TotalPoints = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (PrevTask != i) 
        {
            int tp = v[day][i] + memo(v, day - 1, i,dp);
            TotalPoints = max(TotalPoints, tp);
        }
    }
    return dp[day][PrevTask]=TotalPoints; // maximised
}

int maximumPoints(vector<vector<int>>&v)
{
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return memo(v,n-1,3,dp);
}

//tabulation

