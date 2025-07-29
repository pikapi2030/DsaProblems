#include <bits/stdc++.h>
using namespace std;
/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a
sum goal.
A subarray is a contiguous part of the array.
Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

/*sliding window T.C O(2*2N) S.C O(1)
instead of calculating number of subarrays with sum==goal we will calculate number of
subarrays with sum<=goal (we cant calculate number of subarryas ==goal with sliding window)
num of subArrays with sum==goal = (num subarry with sum<=goal)-(num subarryas with sum <=goal-1)
*/

int subArraysWithSumEqualOrLessThanK(vector<int> &v, int k)
{
    if(k<0){return 0;}
    int sum = 0;
    int n = v.size();
    int cnt = 0;
    int left = 0;
    int right = 0;
    while (right < n)
    {
        sum += v[right];
        while (sum > k&&left<=right)
        {
            sum -= v[left];
            left++;
        }
        cnt += (right - left + 1); // num of subarrays with sum<=k is equal to right-left+1(by permutation)
        right++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return subArraysWithSumEqualOrLessThanK(nums,goal)-subArraysWithSumEqualOrLessThanK(nums,goal-1);
}
