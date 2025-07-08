#include <bits/stdc++.h>
using namespace std;
/*
Given two integers dividend and divisor, divide two integers without using multiplication, 
division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 
32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly 
greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, 
then return -231. 
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
*/

class Solution {
public:
    int divide(long long dividend, long long divisor) 
    {
     long long ans=0;
     if(dividend==divisor){return 1;}
     
     bool sign=true;//positive
     if( dividend<0&&divisor>0 ){ sign=false; }
     if(dividend>0&&divisor<0){sign=false;}
     dividend=abs(dividend);
     divisor=abs(divisor);
     while(  dividend>=divisor )
     {
        long long cnt=0;
        while(dividend>=divisor*pow(2,cnt+1))
        {
            cnt++;
        }
        ans+=pow(2,cnt);
        dividend-=divisor*pow(2,cnt);

     }
     if( ans >= INT_MAX && sign ) return INT_MAX;
if( ans == INT_MAX && !sign ) return -INT_MAX;
if( ans > INT_MAX && !sign ) return INT_MIN;
     if(sign){ return ans; }
     return -ans;

    }
};