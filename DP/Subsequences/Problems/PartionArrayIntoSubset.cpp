#include <bits/stdc++.h>
using namespace std;
/*
You are given an array 'arr' containing 'n' non-negative integers.


Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.


You just need to find the minimum absolute difference considering any valid division of the array elements.


Note:

1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset.

Example:

Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

Ouput: 1

Explanation: We can partition the given array into {3, 1, 5} and {2, 8}.
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).


*/

/*aproach
pre-requisite:- subSetSumK by tabulation
if we notice what does our tabulation table in subSetSumK tells,
DP[i][j] means if  sum J is possible till ith index
now if we want to minimise the absolute difference of partition, we will try to part it in totalsum/2
subsets, and check for the closest to J halfSum  till (n-1)th index which is possible in our DP matrix
*/
int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (auto it : nums)
    {
        totalSum += it;
    }
    int halfSum = totalSum / 2;

    vector<vector<bool>> dp(n, vector<bool>(halfSum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (halfSum >= nums[0])
    {
        dp[0][nums[0]] = true;
    }

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= halfSum; target++)
        {
            bool pick = false;
            if (target >= nums[index])
            {
                pick = dp[index - 1][target - nums[index]];
            }
            bool notPick = dp[index - 1][target];
            dp[index][target] = pick || notPick;
        }
    }
    int SumClosestToHalfSum = 0;
    for (int target = halfSum; target >= 0; target--) // travesing last row of dp array in reverse
    {
        if (dp[n - 1][target] == true) // first TRUE from reverse(larget possible sum till (n-1)th index)
        {
            SumClosestToHalfSum = target;
            break;
        }
    }
    return totalSum - (2 * SumClosestToHalfSum);
}
