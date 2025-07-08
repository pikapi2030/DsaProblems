#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums where every element appears three times except for one,
which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant
extra space.
Example 1:
Input: nums = [2,2,3,2]
Output: 3
Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

/*approach 1:- T.C O(N*32)  S.C O(1)
we count numbers with ith bit set, if numbers with ith bit set are multiple of 3,
then the number which appears only once has ith bit clear(does not contribute in counting as total numbers with ith bit set are a multiple of 3)
if numbers with ith bit set are not multiple of 3, ith bit of the number which appears once
is set
we check this from 0->31 bits and generate our ans
*/
int bitApproach(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int ithBit = 0; ithBit <= 31; ithBit++)
    {
        int cnt = 0; // stores count of numbers with ith bit set
        for (int j = 0; j < n; j++)
        {
            if ((1 << ithBit) & nums[j]) // tells if ith bit of num is set or not
            {
                cnt++;
            }
        }
        if (cnt % 3 != 0)
        {
            ans = (1 << ithBit) | ans; // cnt not multiple of 3, set ith bit of ans
        }
    }
    return ans;
}

/*approach 2:- T.C O(NLogN)+ O(N/3)  S.C O(1)
we sort the nums array, after that clusters will from of same elements, we start from index=1
and traverse the array cluster by cluster( i=i+3 ) and check if i and i-1 are same or not
*/

int sortApproach(vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i = i + 3)
    {
        if (v[i] != v[i - 1])
        {
            return v[i - 1];
        }
    }
    return v[n - 1];
}
/*approach 3:- bucket approach
we create 3 buckets, ones, twos and threes which stores numbers in it on basis of frequency

if a number is in ones, and appears again it will go in twos and we will delete the num from ones
if a number is not in twos it will go in ones(cannot be in threes as this means num occured 4 times hich is not possible (in threes+ once in nums[i]=4 times ))
we do not need to store threes as we do not care about what numbers come in threes
*/

int singleNumber(vector<int> &nums)
{
    int ones=0;
    int twos=0;
    for(auto it:nums)
    {
        ones=~(twos)&it^ones;
        twos=(~ones)&it^twos;//if num is in ones, it will be removed from ones when it comes again beacuse of xor (ones^it) so it will be added in twos
    }
    return ones;
}
