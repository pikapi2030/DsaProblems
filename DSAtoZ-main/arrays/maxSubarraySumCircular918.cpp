#include <bits/stdc++.h>
using namespace std;
/*
Given a circular integer array nums of length n, return the maximum possible sum of a
non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array.
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i]
is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally,
for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with
k1 % n == k2 % n.



Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

*/

/*aproach kadanes algo

    Calculate the max and min subarray sums of the linear array using Kadane's algo.
    If max subarray sum < 0 then all the numbers in the array are negative. 
    Return the max subarray sum.
    Else, return maximum of (a) max_subarray_sum and (b) sum - min_subarray_sum.
    (a) is the case where max subarray is within the linear array boundary.
    (b) is the case where max subarray wraps around the linear array boundary. 
    [5, -1, -2, 5, 6]


*/


int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();
    int maxSubarraySum = 0; // without circular
    int minSubarraysum = 0; // without circular
    int sum1 = 0;
    int sum2 = 0;
    int totalsum = 0;
    int maxElement=INT_MIN;

    for (int i = 0; i < n; i++)
    {
        totalsum += nums[i];
        maxElement = max(maxElement, nums[i]);
        sum1 += nums[i];
        if (sum1 < 0)
        {
            sum1 = 0;
        }
        maxSubarraySum = max(sum1, maxSubarraySum);
        sum2 += nums[i];
        if (sum2 > 0)
        {
            sum2 = 0;
        }
        minSubarraysum = min(sum2, minSubarraysum);
    }
    if (maxSubarraySum == 0)
    {
        return maxElement;
    } // all numbers are negative

    return max(maxSubarraySum, (totalsum- minSubarraysum));
}
