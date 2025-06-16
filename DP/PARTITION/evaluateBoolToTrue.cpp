#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
Problem statement
You are given an expression 'exp' in the form of a string where operands will be :
(TRUE or FALSE), and operators will be : (AND, OR or XOR).
Now you have to find the number of ways we can parenthesize the expression such that it
will evaluate to TRUE.
As the answer can be very large, return the output modulo 1000000007.
Note:
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :
Input: 'exp’ = "T|T & F".
Output: 1
Explanation:
There are total 2  ways to parenthesize this expression:
(i) (T | T) & (F) = F
(ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
*/
/*aproach:-
//! ind always will point to operands, start, end will always point to 'T' ,'F' so while tabulation increment with 2

we will perform partitions at the operand, which allows to get all ways in which an expression
can we solved
we will also have a bool parametre needTrue which will tell what is our function returning?
is it returning number of ways to be true or number of ways to be false,
we need number of ways to be false as well to calculate number of ways to be true, why?
asume:-
t1=num ways exp1 true( can also be said as left part)
t2=num ways exp2 true(can also be said as right part)
f1=num ways exp1 false( can also be said as left part)
f2=num ways exp2 false(can also be said as right part)


let's assume we are partitioning on operand:operator:-
i) (exp1 & exp2), & is the partition
num of ways for whole exp to be true= t1*t2
num of ways for whole exp to be false= t1*f2 + f1*t2 + f1*f2

ii) (exp1|exp2), | is the partition
num ways for whole exp to be true= t1*t2 + t1*f2 +f1*t2
num of ways for whole exp to be false= f1*f2

iii) (exp1^exp2),^ is the partition (xor)  (F^T=T), (T^T=F), (F^F=F), (T^F=T)
num ways for the whole exp to be true= f1*t2 + t1*f2
num ways for the whole exp to be false= t1*t2 + f1*f2

base cases:-
'T', num ways to be true=1
'F', num ways to be false =1
*/

ll rec(string &s, ll start, ll end, bool needTrue)
{
    if (start > end)
    {
        return 0;
    }
    if (start == end)
    {
        if (needTrue)
        {
            return s[start] == 'T';
        }
        else
        {
            return s[start] == 'F';
        }
    }
    ll ways = 0;
    for (ll ind = start + 1; ind <= end - 1; ind += 2) // every operand is at odd index wrt start
    {
        ll lt = rec(s, start, ind - 1, 1); // left True
        ll rt = rec(s, ind + 1, end, 1);   // right True
        ll lf = rec(s, start, ind - 1, 0); // left False
        ll rf = rec(s, ind + 1, end, 0);   // right True
        if (s[ind] == '&')
        {
            if (needTrue)
            {
                ways += lt * rt;
            }
            else // num ways to be false
            {
                ways += lf * rf + lt * rf + lf * rt;
            }
        }
        else if (s[ind] == '|')
        {
            if (needTrue)
            {
                ways += lt * rt + lf * rt + lt * rf;
            }
            else
            {
                ways += lf * rf;
            }
        }
        else if (s[ind] == '^')
        {
            if (needTrue)
            {
                ways += lt * rf + lf * rt;
            }
            else
            {
                ways += lf * rf + lt * rt;
            }
        }
    }
    return ways;
}

ll brute(string &exp)
{
    ll n = exp.size();
    return rec(exp, 0, n - 1, 1); // needTrue=1 means return num ways to get true
}
// tabulation(3D dp)
ll evaluateExp(string &s)
{
    ll n = s.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = 0; i < n; i += 2)
    {
        if (s[i] == 'T')
        {
            dp[i][i][1] = 1;
        }
        else if (s[i] == 'F')
        {
            dp[i][i][0] = 1;
        }
    }

    for (ll start = n - 1; start >= 0; start -= 2)

    {
        for (ll end = start + 2; end <= n - 1; end += 2) //! make sure end=start+2
        {

            for (ll needTrue = 0; needTrue <= 1; needTrue++)
            {
                ll ways = 0;

                for (ll ind = start + 1; ind <= end - 1; ind += 2) // every operand is at odd index wrt start
                {
                    ll lt = dp[start][ind - 1][1]; // left True
                    ll rt = dp[ind + 1][end][1];   // right True
                    ll lf = dp[start][ind - 1][0]; // left False
                    ll rf = dp[ind + 1][end][0];   // right False
                    if (s[ind] == '&')
                    {
                        if (needTrue)
                        {
                            ways += lt * rt;
                        }
                        else // num ways to be false
                        {
                            ways += lf * rf + lt * rf + lf * rt;
                        }
                    }
                    else if (s[ind] == '|')
                    {
                        if (needTrue)
                        {
                            ways += lt * rt + lf * rt + lt * rf;
                        }
                        else
                        {
                            ways += lf * rf;
                        }
                    }
                    else if (s[ind] == '^')
                    {
                        if (needTrue)
                        {
                            ways += lt * rf + lf * rt;
                        }
                        else
                        {
                            ways += lf * rf + lt * rt;
                        }
                    }
                }
                dp[start][end][needTrue] = ways;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << " " << dp[i][j][k] << " ";
            }
            cout << "||";
        }
        cout << endl;
    }
    cout << endl;

    return dp[0][n - 1][1];
}

int main()
{
    string s = "T^F&T|F";
    cout << evaluateExp(s);
}
