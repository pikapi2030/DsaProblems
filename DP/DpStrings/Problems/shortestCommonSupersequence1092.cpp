#include <bits/stdc++.h>
using namespace std;
/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as 
subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t 
(possibly 0) results in the string s.
Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
*/

/*aproach
//!minLenghtOfsupersequence= lcs+ (n-lcs)(insertion) + (m-lcs)(insertion)= n+m-lcs
to print supersequence:-
when we print lcs, if mismatch we will print the letter whoo's value is smaller in out table
*/

vector<vector<int>> lcsTab(string a,string b)
{
    int as=a.size();
    int bs=b.size();
    vector<vector<int>>dp(bs+1,vector<int>(as+1,0));
    for(int indb=1;indb<=bs;indb++)
    {
        for(int inda=1;inda<=as;inda++)
        {
          if( a[inda-1]==b[indb-1] )
          {
            dp[indb][inda]=1+dp[indb-1][inda-1];
          }
          else
          {
            dp[indb][inda]=max( dp[indb-1][inda],dp[indb][inda-1]);
          }
        }
    }
    return dp;
}

string printSuperSeq(string a,string b)
{
    
    vector<vector<int>>dp=lcsTab(a,b);
    int as=a.size();
    int bs=b.size();
    string ans;
    int inda=as;
    int indb=bs;
    int i=0;
    while(inda>0&&indb>0)
    {
     if(a[inda-1]==b[indb-1])
     {
      ans.push_back(a[inda-1]);
      inda--;
      indb--; 
     }
     else if(dp[indb-1][inda]>=dp[indb][inda-1])
     {
        ans.push_back(b[indb-1]);
        indb--;
     }
     else //dp[indb][inda-1]>dp[indb-1][inda]
     {
        ans.push_back(a[inda-1]);
        inda--;
     } 
    }
    while(inda>0)
    {
        ans.push_back(a[inda-1]);
        inda--;
    }
    while(indb>0)
    {
        ans.push_back(b[indb-1]);
        indb--;
    }
reverse(ans.begin(),ans.end());
    return ans;
}

