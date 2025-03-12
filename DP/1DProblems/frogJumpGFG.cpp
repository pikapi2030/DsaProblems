#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array h[] where h[i] represents the h of the i-th stair,
a frog starts from the first stair and wants to reach the top. From any stair i,
the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair.
The cost of a jump is the absolute difference in h between the two stairs.
Determine the minimum total cost required for the frog to reach the top.
*/

/*aproach 1: recursion
we will try all possible ways and return minimum energy
*/

int bruteRecur(int cur, vector<int> &h)
{
    if (cur == h.size() - 1)
    {
        return 0; // energy reqired to reach last index from last index is 0
    }
    int oneJumpEnergy = bruteRecur(cur + 1, h) + abs(h[cur] - h[cur + 1]);
    if (cur + 2 < h.size()) // a jump of 2 is possible
    {
        int twoJumpEnergy = bruteRecur(cur + 2, h) + abs(h[cur + 2] - h[cur]);

        return min(oneJumpEnergy, twoJumpEnergy);
    }
    else
    {
        return oneJumpEnergy;
    } // a jump of 2 is not possible
}
/*better
applying memoisation
T.C O(2*N) S.C O(2N)
*/
int memo(int cur, vector<int> &h, vector<int> &dp)

{

    if (cur == h.size() - 1)
    {
        return 0; // energy reqired to reach last index from last index is 0
    }
    if (dp[cur] != -1)
    {
        return dp[cur];
    }
    int oneJumpEnergy = memo(cur + 1, h, dp) + abs(h[cur] - h[cur + 1]);
    if (cur + 2 < h.size()) // a jump of 2 is possible
    {
        int twoJumpEnergy = memo(cur + 2, h, dp) + abs(h[cur + 2] - h[cur]);

        return dp[cur] = min(oneJumpEnergy, twoJumpEnergy);
    }
    else
    {
        return dp[cur] = oneJumpEnergy;
    }
}

/*tabulation
T.C O(N), O(N)
*/

int tab(vector<int> &h)
{

    int n = h.size();
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return abs(h[0] - h[1]);
    }
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    dp[n - 2] = abs(h[n - 2] - h[n - 1]);
    for (int i = n - 3; i >= 0; i--)
    {
        int oneJump = abs(h[i] - h[i + 1]) + dp[i + 1];
        int twoJump = abs(h[i] - h[i + 2]) + dp[i + 2];
        dp[i] = min(oneJump, twoJump);
    }
    return dp[0];
}

/*optimal aproach
as we can see we only need dp[i+1], dp[i+2], not the whole array at same time
so we can use a couple of variables and optimise on S.C

T.C O(N),S.C O(1)
*/

int opti(vector<int> &h)
{
    int n = h.size();
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return abs(h[0] - h[1]);
    }
    int next = abs(h[n - 2] - h[n - 1]);// next wrt i
    int nextOfnext = 0;//nextOfnext wrt to i
    for (int i = n - 3; i >= 0; i--)
    {
        int oneJump = abs(h[i] - h[i + 1]) + next;
        int twoJump = abs(h[i] - h[i + 2]) + nextOfnext;
        int cur= min(oneJump, twoJump);
        nextOfnext=next;
        next=cur;
    }
    return next;
}

int minCost(vector<int> &h)
{
    int n = h.size();
    vector<int> dp(n + 1, -1);
    return memo(0, h, dp);
}
int main()
{
    vector<int> h = {20, 30, 40, 20};
    cout << minCost(h);
}
