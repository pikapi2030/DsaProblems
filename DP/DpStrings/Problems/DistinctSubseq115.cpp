#include <bits/stdc++.h>
using namespace std;
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
*/

/*aproach
we are checking if how many subsequences of string A are same as string B
we use inda,indb for pointing at strings
F(a,b) represents number of subsequences of str A till ath index same as B till bth index
if inda=indb, retrun 
f(inda-1,indb-1)(ticked the element in B, moving further) + f(inda-1,indb)(decided not to tick the element in B,to explore all possiblities)

if there is a mismatch, return f(inda-1,indb) (moving further)
base cases:-
if all of string A is used(inda<0), then we could not match all elements of B to A, return 0(no subsequence of A is B)
if all of string B is used(we matched all elements of B with A, thus a subsequence of A is B),return 1
*/

//recursion

int recur(string s,string t,int inds,int indt)
{
if(indt<0){return 1;}
if(inds<0){return 0;}

if(s[inds]==t[indt])
{
    return recur(s,t,inds-1,indt-1)+recur(s,t,inds-1,indt);
}
else
{
    return recur(s,t,inds-1,indt);
}

}

int Brute(string s, string t) 
{
  return recur(s,t,s.size()-1,t.size()-1);      
}
//tabulation
int tab(string s,string t)
{
    int ss=s.size();
    int ts=t.size();
    vector<vector<int>>dp(ss+1,vector<int>(ts+1,0));
    for(int i=0;i<=ss;i++)
    {
        dp[i][0]=1;//base case
    }
    for(int inds=1;inds<=ss;inds++)
    {
        for(int indt=1;indt<=ts;indt++)
        {
            if(s[inds-1]==t[indt-1])
            {
                dp[inds][indt]=dp[inds-1][indt-1]+dp[inds-1][indt];
            }
            else
            {
                dp[inds][indt]=dp[inds-1][indt];
            }
        }
    }
    return dp[ss][ts];
}

