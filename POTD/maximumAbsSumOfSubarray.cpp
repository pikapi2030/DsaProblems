#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array nums. The absolute sum of a subarray
[numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

*/

/*aproach
max abs sum will be max of (maxSum,minSum), maxSumn  and minSum of all subarray are calculated
normally,withou any abs condition

to calculated max sum and min sum of all subarray, use kadane's algorithm
*/

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {

        int maxsum = 0;
        int sum1 = 0;
        for (int i = 0; i < nums.size(); i++) // calculating max sum possible without the abs condition
        {
            sum1 = sum1 + nums[i];
            if (sum1 < 0)
            {
                sum1 = 0;
            }
            maxsum = max(maxsum, sum1);
        }

        int sum2 = 0;
        int minsum = 0;

        for (int i = 0; i < nums.size(); i++) // calculating minsum possible without abs
        {
            sum2 += nums[i];
            if (sum2 > 0)
            {
                sum2 = 0;
            }
            minsum = min(minsum, sum2);
        }
        return max(maxsum, abs(minsum)); // max sum with abs will we max of maxsum and abs of minsum
    }
};