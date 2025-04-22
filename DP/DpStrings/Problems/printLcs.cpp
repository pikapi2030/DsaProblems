#include <bits/stdc++.h>
using namespace std;
/*
print lcs between two strings
*/

/*aproach, i is index of a, j is index of b
we can find our lcs by using dp table generated during tabulation
we are trying to find where did dp[i][j] come from
we start from n,m
if(a[i-1]==b[j-1])(shifted indexes)
{
this element is part of our lcs( our lcs is generated in reverse order )
move to upper diagnal ( i-1,j-1 )
}
else
{
move to where dp[i][j] came from, we know if (a[i]!=b[j]) {dp[i][j]=max(dp[i-1][j],dp[i][j-1])
so move to (i-1,j) or (i,j-1) depending on which one is larger (if both same then there can be multiple lcs, move to either )
}
}
do this till i||j become 0
*/
vector<vector<int>> Tabulation(string a, string b)
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
    return dp;
}

string findLCS(int n, int m, string &a, string &b)
{
    vector<vector<int>> tab = Tabulation(a, b);
    string ans = "";
    int lengthOfLcs = tab[n][m];
    for (int i = 0; i < lengthOfLcs; i++)
    {
        ans += "$"; // generating a dummy string of size equal to lcs
    }
    int i = n, j = m;
    int indexOfLcs = lengthOfLcs - 1; // index is from reverse as string is generated in reverse
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans[indexOfLcs] = a[i - 1]; // i-1 because shifted indexes
            indexOfLcs--;
            i--;
            j--; // moving to upper diagonal
        }
        else if (tab[i][j - 1] > tab[i - 1][j])
        {
            j = j - 1; // moving to max
        }
        else
        {
            i = i - 1; // moving to max
        }
    }
    return ans;
}
