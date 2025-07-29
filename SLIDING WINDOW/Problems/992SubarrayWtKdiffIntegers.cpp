#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3],
[1,2,1], [2,1,2], [1,2,1,2]
Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

int subarrayWithLessThanKdistinct(vector<int> &v, int k)
{
    if (k < 0)
    {
        return 0;
    }
    int ans = 0;
    map<int, int> mp;
    int left = 0, right = 0;
    while (right < v.size())
    {
        mp[v[right]]++;
        if (mp.size() > k)
        {
            mp[v[left]]--;
            if (mp[v[left]] == 0)
            {
                mp.erase(v[left]);
            }
            left++;
        }
        ans += right - left + 1;
        right++;    ww
    }
    return ans;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return subarrayWithLessThanKdistinct(nums, k) - subarrayWithLessThanKdistinct(nums, k - 1);
}
