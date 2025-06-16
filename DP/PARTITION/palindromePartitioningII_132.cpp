#include <bits/stdc++.h>
using namespace std;
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:
Input: s = "a"
Output: 0
Example 3:
Input: s = "ab"
Output: 1
*/
/*approach
we take an index which indicates starting point of our partitioning,
from this index we try every way to partition by going from i=index to n,
i is where we partition
we can partition if index->i is a pal

this index then traverses the whole string, changing our starting point to calculate
all ways of partitioning 

we can  make a bool matrix v[i][j] which tell if string from i to j is pal or not
we pre compute this matrix
*/

vector<vector<bool>> isPalPrecompute(string &s)
{
    int n = s.size();
    vector<vector<bool>> ans(n, vector<bool>(n, 0));

    for (int i = n-1; i >=0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if( s[i]==s[j]&&(j-i<=1||ans[i+1][j-1]))
            {
                ans[i][j]=true;
            }
        }
    }
    return ans;
}

int rec(string &s, vector<vector<bool>> &isPal, int index)
{
    int n = s.size();
    if (index == n)
    {
        return 0;
    }
    if (isPal[index][n - 1])
    {
        return 0;
    }
    int mini = 1e9;
    for (int i = index; i < n; i++)
    {
        int cuts = 1e9;
        if (isPal[index][i])
        {
            cuts = 1 + rec(s, isPal, i + 1);
        }
        mini = min(cuts, mini);
    }
    return mini;
}

int brute(string &s)
{
    vector<vector<bool>> isPal = isPalPrecompute(s);
    return rec(s, isPal, 0);
}
// tabulation
int minCuts(string &s)
{
    int n = s.size();
    vector<vector<bool>> isPal = isPalPrecompute(s);
    vector<int> dp(n + 1, 1e9);
    //base cases
    dp[n] = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPal[i][n - 1])
        {
            dp[i] = 0;
        }
    }

    for (int index = n - 1; index >= 0; index--)
    {
        int mini = 1e9;
        for (int i = index; i < n; i++)
        {
            int cuts = 1e9;
            if (isPal[index][i])
            {
                cuts = 1 + dp[i + 1];
            }
            dp[index] = min(cuts, dp[index]);
        }
    }

    return dp[0];
}
int main()
{
    string s = "aab";
    auto v=isPalPrecompute(s);
    for(auto it:v)
    {
        for( auto ij:it)
        {
            cout<<" "<<ij<<" ";
        }
        cout<<endl;
    }
}
