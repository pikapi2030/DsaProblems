#include <bits/stdc++.h>
using namespace std;

/*
given an array cuts, cuts[i]=places you can cut on the stick, in any order
example:- cuts={1,5,7} means you can cut on 1st,5th,7th mark on the stick
you may cut 7th mark first, or 5th mark first in any way such that cost of cutting is
min
cost of cutting= length of the stick(before cut) so it does not matter where you cut,
your first cut's cost will be equal to initial lenght of the stick
*/

int rec(vector<int> &cuts, int start_stick, int end_stick, int startCutArray, int endCutArray)
{
    if (startCutArray > endCutArray)
    {
        return 0;
    }
    int minCost = 1e9;
    for (int cutArrayIndex = startCutArray; cutArrayIndex <= endCutArray; cutArrayIndex++)
    {
        // cuts[cutArrayIndex]=where we are cutting stick from
        int leftCost = rec(cuts, start_stick, cuts[cutArrayIndex], startCutArray, cutArrayIndex - 1);
        int rightCost = rec(cuts, cuts[cutArrayIndex], end_stick, cutArrayIndex + 1, endCutArray);
        int totalCost = (end_stick - start_stick) + leftCost + rightCost;
        minCost = min(minCost, totalCost);
    }
    return minCost;
}

int intuitiveRecursion(int c, vector<int> &cuts) // c=length of stick
{
    sort(cuts.begin(), cuts.end());
    return rec(cuts, 0, c, 0, cuts.size() - 1);
}
// better recursion (instead of using 4 vars, we use 2 only)
/*
instead of calculating length of the stick from start and end stick,we try to get it from
left and right itself
we insert a 0 and lenght of stick at start and end of the stick respectively
so length the stick= cuts[left-1]+cuts[right+1], where left, and right indicate our cut range
(pointers pointing to cut array)
*/

int twoVarRec(vector<int> &cuts, int startCutArray, int endCutArray)
{
    if (startCutArray > endCutArray)
    {
        return 0;
    }
    int minCost = 1e9;
    for (int cutArrayIndex = startCutArray; cutArrayIndex <= endCutArray; cutArrayIndex++)
    {
        int leftCost = twoVarRec(cuts, startCutArray, cutArrayIndex - 1);
        int rightCost = twoVarRec(cuts, cutArrayIndex + 1, endCutArray);
        int cost = (cuts[endCutArray + 1] - cuts[startCutArray - 1]) + leftCost + rightCost;
        minCost = min(cost, minCost);
    }
    return minCost;
}

int betterRecursion(int c, vector<int> &cuts) // c=length of stick
{
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(c);
    sort(cuts.begin(), cuts.end());
    return twoVarRec(cuts, 1, cuts.size() - 2);
}
// memoisation

int mem(vector<int> &cuts, int startCutArray, int endCutArray, vector<vector<int>> &dp)
{

    if (startCutArray > endCutArray)
    {
        return 0;
    }
    if (dp[startCutArray][endCutArray] != -1)
    {
        return dp[startCutArray][endCutArray];
    }
    int minCost = 1e9;
    for (int cutArrayIndex = startCutArray; cutArrayIndex <= endCutArray; cutArrayIndex++)
    {
        int leftCost = mem(cuts, startCutArray, cutArrayIndex - 1, dp);
        int rightCost = mem(cuts, cutArrayIndex + 1, endCutArray, dp);
        int cost = (cuts[endCutArray + 1] - cuts[startCutArray - 1]) + leftCost + rightCost;
        minCost = min(cost, minCost);
    }
    return dp[startCutArray][endCutArray] = minCost;
}

int memo(int c, vector<int> &cuts) // c=length of stick
{
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(c);
    sort(cuts.begin(), cuts.end());
    int n = cuts.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return mem(cuts, 1, cuts.size() - 2, dp);
}

// tabulation
int tab(int c, vector<int> &cuts)
{
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(c);
    sort(cuts.begin(), cuts.end());
    int n = cuts.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int left = n - 2; left >= 1; left--)
    {
        for (int right = 1; right <= n - 2; right++)
        {
            if (left > right)
            {
                continue;
            }
            int mini = 1e9;
            for (int cutPosInd = left; cutPosInd <= right; cutPosInd++)
            {
                int cost = dp[left][cutPosInd - 1] + dp[cutPosInd + 1][right] + (cuts[right + 1] - cuts[left - 1]);
                mini = min(cost, mini);
            }
            dp[left][right] = mini;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<" "<<dp[i][j]<<" ";
        }
        cout << endl;
    }
    return dp[1][n - 2];
}

int main()
{
    vector<int>c={4,7,9};
    cout<<tab(12,c);
}
