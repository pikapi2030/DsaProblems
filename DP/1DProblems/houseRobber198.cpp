#include <bits/stdc++.h>
using namespace std;
/*
You are a professional robber planning to rob houses along a street. Each house has a
certain amount of money stashed, the only constraint stopping you from robbing each of
them is that adjacent houses have security systems connected and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the
maximum amount of money you can rob tonight without alerting the police.

Example :1

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

!example 2:
nums=[2,1,1,2] max amount=4 (house 1 and house 4)
*/

/*aproach
in this quetion we have basically calculate maximum subsequence sum without having any
adjacent elements

we will use recursion(backtracking) to calculate sum of subsequences with no adjacent element
and then try to optimise using DP

*/

/*ALL T.C AND S.C
brute recursion  T.C O(2^N),S.C O(N+N) 
*/
int helper(vector<int> &v, vector<int> &temp, int cur, int sum)
{
    if (cur >= v.size())
    {
        return sum;
    }
    sum += v[cur];
    //! if we picked cur, then we will call for cur+2(adjacent indexes not allowed)
    int pick = helper(v, temp, cur + 2, sum);
    sum -= v[cur];
    int notPick = helper(v, temp, cur + 1, sum);
    return max(pick, notPick);

}

int bruteR(vector<int> &v)
{
    int n=v.size();
    vector<int>temp;
    return helper(v,temp,0,0);
}
