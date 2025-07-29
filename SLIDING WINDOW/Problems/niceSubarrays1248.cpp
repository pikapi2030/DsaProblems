#include <bits/stdc++.h>
using namespace std;
/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if
there are k odd numbers on it.
Return the number of nice sub-arrays.
Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

/*sliding window
we know we can calculate number of subarrays with sum k if the array is binaryy (problem 930)
so we will change every odd number=1 and every even number =0, and the problem now is
exaclty same as the problem 930
*/

int subArraysWithSumEqualOrLessThanK(vector<int> &v, int k)
{
    if (k < 0)
    {
        return 0;
    }
    int sum = 0;
    int n = v.size();
    int cnt = 0;
    int left = 0;
    int right = 0;
    while (right < n)
    {
        sum += v[right];
        while (sum > k && left <= right)
        {
            sum -= v[left];
            left++;
        }
        cnt += (right - left + 1); // num of subarrays with sum<=k is equal to right-left+1(by permutation)
        right++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
  for(int i=0;i<nums.size();i++)
  {
    if (nums[i]%2==0)
    {
        nums[i]=0;
    }
    else
    {
        nums[i]=1;
    }
  }

    return subArraysWithSumEqualOrLessThanK( nums,k )-subArraysWithSumEqualOrLessThanK(nums,k-1);
}
