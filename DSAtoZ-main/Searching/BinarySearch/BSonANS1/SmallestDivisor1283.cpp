#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer threshold, 
we will choose a positive integer divisor, divide all the array by it, 
and sum the division's result. Find the smallest divisor such that the
 result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater
 than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor 
is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/

/*same quetion as koko eating bananas

T.C O(N*log_2 (max));(range of BS is 1 to max)
*/
long long maxOFaVector(vector<int> v)

{
    long long max = LONG_LONG_MIN;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*(it) > max)
        {
            max = *(it);
        }
    }
    return max;
}

int isPossibleDivisor(vector<int>v,int k,int threshold)
{
    long long sum=0;
    for(int i=0;i<v.size();i++)
    {
     sum=sum+ceil((double)v[i]/(double)k);
    }
    if(sum<=threshold)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

}

int mysol(vector<int>v,int threshold)
{
long long low=1,high=maxOFaVector(v);
while(high>=low)
{
    long long mid=(high+low)/2;

    if(isPossibleDivisor(v,mid,threshold))
    {
      high=mid-1;
    }
    else
    {
        low=mid+1;
    }

}
return low;
}


