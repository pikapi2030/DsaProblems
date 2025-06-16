#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that
subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that
the answer fits in a 32-bit integer.
Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:
Input: arr = [1], k = 1
Output: 1
*/

int rec(vector<int> &v, int k, int index)
{
    int n = v.size();

    if (index >= n)
    {
        return 0;
    }
    int maxi = 0;
    int maxElement = 0;
    for (int i = index; i < min(index + k, n); i++) // partition from index to i
    // we can max part k length partitions, and index+k can pass n so min(n,ind+k)

    {
        int sum = 0;
        maxElement = max(maxElement, v[i]); // since maxElement is initialized in the function, it makes sure that it is from index to i
        sum = (i - index + 1) * maxElement + rec(v, k, i + 1);
        maxi = max(sum, maxi);
    }
    return maxi;
}

int Brute(vector<int> &v, int k)
{
    return rec(v, k, 0);
}
// tabs
int maxSumAfterPartitioning(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> dp(n+1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int maxElement = 0;
        for (int i = ind; i < min(ind + k, n); i++) // partition from index to i
        // we can max part k length partitions, and index+k can pass n so min(n,ind+k)

        {
            int sum = 0;
            maxElement = max(maxElement, v[i]); // since maxElement is initialized in the function, it makes sure that it is from index to i
            sum = (i - ind + 1) * maxElement + dp[i + 1];
            dp[ind] = max(sum, dp[ind]);
        }
    }
    return dp[0];
}
