#include <bits/stdc++.h>
using namespace std;
/*
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some
characters (can be none) deleted without changing the relative order of the remaining
characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

*/

/*aproach
we will use a two indexed aproach (to refer to two strings given) ind1 and ind2

F(ind1,ind2) represents longest subsequence between strings till their respective indexes

if(s1[ind1]==s2[ind2] ) , then lcs= 1+F(ind1-1,ind2-1)
if(s1[ind1]!=s2[ind2]), lcs=max(F(ind1-1,ind2),F(ind1,ind2-1))
base case if either of indexes become negative , return 0 (no common subsequence as one of the string does not exist)

*/

//! Brute recursion  T.C O(2^n * 2^m) S.C O(N+M)

int recur(string s1, string s2, int ind1, int ind2)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    } // base case

    if (s1[ind1] == s2[ind2])
    {
        return 1 + recur(s1, s2, ind1 - 1, ind2 - 1);
    }
    // s1[ind1]!=s2[ind2]
    return max(recur(s1, s2, ind1 - 1, ind2), recur(s1, s2, ind1, ind2 - 1));
}

int Brute(string s1, string s2)
{
    return recur(s1, s2, s1.size() - 1, s2.size() - 1);
}

// memoisation T.C O(N*M) S.C O(N+M)+O(N*M)
int mem(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{

    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    } // base case
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (s1[ind1] == s2[ind2])
    {
        return dp[ind1][ind2] = 1 + mem(s1, s2, ind1 - 1, ind2 - 1, dp);
    }
    // s1[ind1]!=s2[ind2]
    return dp[ind1][ind2] = max(mem(s1, s2, ind1 - 1, ind2, dp), mem(s1, s2, ind1, ind2 - 1, dp));
}

int memo(string s1, string s2)
{
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    return mem(s1, s2, s1.size() - 1, s2.size() - 1, dp);
}

/*tabulation
since our base has -1 as an index, we ill shift our indexes to right side by 1 magnitude
*/
int Tabulation(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int inda = 1; inda <= n; inda++) // indexes shifted to right
    {
        for (int indb = 1; indb <= m; indb++)
        {
            if (a[inda - 1] == b[indb - 1])
            {
                dp[inda][indb] = 1 + dp[inda - 1][indb - 1];
            }
            else
            {
                dp[inda][indb] = max(dp[inda - 1][indb], dp[inda][indb - 1]);
            }
        }
    }
    return dp[n][m];
}
//space optimisation dp[inda][...] replaced by cur[...], dp[inda-1][...] replaced by pre[...]
int twoArray(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<int>prev(m+1,0);
    vector<int>cur(m+1,0);

    for (int inda = 1; inda <= n; inda++) // indexes shifted to right
    {
        for (int indb = 1; indb <= m; indb++)
        {
            if (a[inda - 1] == b[indb - 1])
            {
                cur[indb] = 1 + prev[indb - 1];
            }
            else
            {
                cur[indb] = max(prev[indb], cur[indb - 1]);
            }
        }
        prev=cur;
    }
    return prev[m];
}
