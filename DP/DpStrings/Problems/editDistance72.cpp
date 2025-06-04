#include <bits/stdc++.h>
using namespace std;
/*
Given two strings word1 and word2, return the minimum number of operations required to convert
word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

/*aproach:-
i is index to string we perform operations on
if same, then F(i-1,j-1)
if no same then:-
replace:- 1+F(i-1,j-1)
delete:- 1+F(i-1,j)
insert:- 1+F(i,j-1)
*/

int recur(string s, string t, int si, int tj)
{
    if( si<0 )
    {
     return tj+1;
    }
    if(tj<0)
    {
     return si+1;
    }
    if (s[si] == t[tj])
    {
        return recur(s, t, si - 1, tj - 1);
    }

    else
    {
        int temp = max(1 + recur(s, t, si - 1, tj), 1 + recur(s, t, si, tj - 1));
        return max(temp, 1 + recur(s, t, si - 1, tj - 1));
    }
}

int recurence(string s, string t)
{
    return recur(s, t, s.size() - 1, t.size() - 1);
}

//tabulation
int minDistance(string s, string t) 
{
int ss=s.size();
int ts=t.size();
vector<vector<int>>dp(ss+1,vector<int>(ts+1,0));
for(int i=0;i<=ss;i++)
{
    dp[i][0]=i;
}
for(int i=0;i<=ts;i++)
{
    dp[0][i]=i;
}

for(int si=1;si<=ss;si++)
{
    for(int ti=1;ti<=ts;ti++)
    {
        if(s[si-1]==t[ti-1])
        {
        dp[si][ti]=dp[si-1][ti-1];
        }
        else
        {
            int temp=min(1+dp[si][ti-1],1+dp[si-1][ti]);
            dp[si][ti]=min(temp,1+dp[si-1][ti-1]);
        }
    }
}
return dp[ss][ts];

}
