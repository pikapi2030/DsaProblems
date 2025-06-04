#include <bits/stdc++.h>
using namespace std;
//min insertions to make a string palindrome
/*aproach:- we will keep longest palindrome unchanged and insert other umatching characters between
out longest palindrome to make the string palindrome
//!ans= n-(longest palindromic subsequence) 
*/
int LCsubsequence(string a, string b)
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

int longestPalindromeSubseq(string s) 
{
string org=s;    
reverse(s.begin(),s.end());//in-place funtion, it does not return a value but changes the passed string
return LCsubsequence(org,s);
}

int minInsertions(string s) 
{
return s.size()-longestPalindromeSubseq(s);    
}