#include <bits/stdc++.h>
using namespace std;

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

//longest palindromic subsequence in a string
/*aproach:- longest palindromic subsequence in a string is longest common subsequnece 
between that string and reverse of it
return lcs(s1,rev(s1));
*/
int longestPalindromeSubseq(string s) 
{
string org=s;    
reverse(s.begin(),s.end());//in-place funtion, it does not return a value but changes the passed string
return LCsubsequence(org,s);
}