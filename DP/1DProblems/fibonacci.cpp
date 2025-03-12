#include <bits/stdc++.h>
using namespace std;
/*
nth fibonacci number using dp
T.C O(N) S.C O(N)+O(N) //array + recursion stack space    
*/

int fib(int n,vector<int>&dp)
{
if(n<=1){return n;}

if(dp[n]!=-1)
{
    return dp[n];
}
return dp[n]=fib(n-1,dp)+fib(n-2,dp);//returns the ans and stores it in dp as well
}

//better solution :- since recursion takes extra space, we will do it iteratively 
//Bottom up aproach, we fill the dp array from bottom(from base cases), also called tabulation
//T.C O(N) S.C O(N)//no recursion call
int F(int n)
{
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//BEST SOLUTION, instead of using a dp array, we will use to variables
//T.C O(N) //!S.C O(1)
//!there is still a better way to do this, called matrix exponentiation, T.C LOG(N)
int opti(int n)
{
    int prevofPrev=0;
    int prevAns=1;
    for(int i=2;i<=n;i++)
    {
     int curAns=prevAns+prevofPrev;
     prevofPrev=prevAns;
     prevAns=curAns;

    }
    return prevAns;
}


int main()
{
    int n;
    cin>>n;
    cout<<opti(n);
}

