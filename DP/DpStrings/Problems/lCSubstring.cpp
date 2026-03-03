#include <bits/stdc++.h>
using namespace std;
//longest common substring



/*recursive aproach
we use a third variable count, if s1[i]==s2[j], we return F(i-1,j-1,count+1)
else we return max( count,max(F(i-1,j,0),F(i,j-1,0)))
we are reseting the count if mismatch then calling 

*/

/*TabulationAproach
we will use lcsubsequence, but when we mismatch, we put dp[i][j]=0, our ans is max value from 
the dp table
*/


int LongestCommonSubstring(string a, string b)
{
    int ans=0;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int inda = 1; inda <= n; inda++) // indexes shifted to right(1 based indexing)
    {
        for (int indb = 1; indb <= m; indb++)
        {
            if (a[inda - 1] == b[indb - 1])
            {
                dp[inda][indb] = 1 + dp[inda - 1][indb - 1];
                ans=max(ans,dp[inda][indb]);
            }
          
        }
    }
    return ans;
}
