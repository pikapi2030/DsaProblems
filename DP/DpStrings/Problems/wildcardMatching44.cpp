#include <bits/stdc++.h>
using namespace std;
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with
support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/
//! i have mistakelny taken s as p and p as s(wrong wrt example), so just reverse the arguments
bool recur(string s, string p, int si, int pi)
{
    if (si < 0 && pi < 0)
    {
        return true; // both matched
    }
    if (si < 0 && pi >= 0)
    {
        return false; // s ended, p left, could not match
    }

    if (pi < 0 && si >= 0)
    {
        // only possible to match if entire s string till si is *
        for (int i = 0; i <= si; i++)
        {
            if (s[si] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (s[si] == p[pi] || s[si] == '?')
    {
        return recur(s, p, si - 1, pi - 1);
    }
    else if (s[si] == '*')
    {
        // first choose * as nothing, basically (si-1,pi) as we did not match star with anything, we shrink s
        /*second we have to match * with first character at pi, then first two at pi, then first 3 at pi
        and so on... we can do this with a for loop, another way to simply don't shrink *(call for (si,pi-1))
        pi-1 means we have matched the first at pi with start, when this functions gets called, it will also call
        for other matches as * is not shrinked (it is shrinked as well in the other function call)
        */
        return recur(s, p, si - 1, pi) || recur(s, p, si, pi - 1);
    }
    else
    {
        return false; // mismatch as no equal char,? or * is present
    }
}

bool Brute(string s, string p)
{
    return recur(p, s, p.size() - 1, s.size() - 1);
}
//! tabulation, this time with correct names(p-> string containing *,? and lowercase s->only lowercase letters)
bool isMatch(string s, string p)
{
    int ss = s.size();
    int ps = p.size();
    vector<vector<bool>> dp(ps + 1, vector<bool>(ss + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= ss; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= ps; i++)
    {
        dp[i][0]=(dp[i-1][0]&& p[i-1]=='*');//it is to check if p is * till pi      
    }
    for(int pi=1;pi<=ps;pi++)
    {
        for(int si=1;si<=ss;si++)
        {
          if(p[pi-1]==s[si-1]||p[pi-1]=='?')
          {
            dp[pi][si]=dp[pi-1][si-1];
          }
          else if(p[pi-1]=='*')
          {
            dp[pi][si]=(dp[pi-1][si]||dp[pi][si-1]);
          }
          else
          {
            dp[pi][si]=0;
          } 
        }
    }
    return dp[ps][ss];      
}
