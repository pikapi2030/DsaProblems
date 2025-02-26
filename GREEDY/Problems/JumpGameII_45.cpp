#include <bits/stdc++.h>
using namespace std;
/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at
nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i.
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated
such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

/*BRUTE APROACH T.C O(N^N) S.C O(N)
use every possible way(by recursion)
*/
int recur(int start, int cnt, vector<int> &nums)
{
    if (start >= nums.size() - 1)
    {
        return cnt;
    }
    int minJump = INT_MAX;
    for (int i = start + 1; i <= nums[start] + start; i++)
    {

        minJump = min(recur(i, cnt + 1, nums), minJump);
    }
    return minJump;
}

int BRUTE(vector<int> &nums)
{
    int start = 0;
    int cnt = 0;
    cnt = recur(start, cnt, nums);
    return cnt;
}

/*greedy aproach T.C O(N), S.C O(1)*/

int jump(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    int cnt = 1;
    int curIndex = 0;
    while (curIndex < n - 1)
    {
        if (curIndex + nums[curIndex] >= n - 1)
        {
            return cnt;
        }

        int indexOfMaxReachability = 0;
        int MaxReachability = 0;

        for (int j = curIndex + 1; j <= nums[curIndex] + curIndex; j++)
        {

            if (j < n && nums[j] + j >= MaxReachability)
            {
                MaxReachability = nums[j] + j;
                indexOfMaxReachability = j;
            }
        }
        curIndex = indexOfMaxReachability;
        cnt++;
    }
    return cnt;
}
