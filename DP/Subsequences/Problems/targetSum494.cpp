#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-'
before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.



Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1

*/

/* brute aproach
pick +ve pick -ve aproach
*/

int recur(vector<int> &nums, int target, int index)
{
    if (index == 0)
    {
        if (nums[0] == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int negative = recur(nums, target - nums[index], index - 1);
    int positive = recur(nums, target + nums[index], index - 1);
    return negative + positive;
}

int BRUTE(vector<int> &nums, int target)
{
    return recur(nums, target, nums.size() - 1);
}

/*memoisation, but you may say target can become negative
so we will simply apply an offset
*/
int solve(vector<int> &nums, int target, int index, int ans, vector<vector<int>> &dp, int offset)
{
    if (index == nums.size())
    {
        return ans == target ? 1 : 0;
    }

    if (dp[index][ans + offset] != -1)
    {
        return dp[index][ans + offset];
    }

    int include = solve(nums, target, index + 1, ans + nums[index], dp, offset);
    int exclude = solve(nums, target, index + 1, ans - nums[index], dp, offset);

    return dp[index][ans + offset] = include + exclude;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int offset = sum; // offset to handle negative indices

    vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1)); // size adjusted for negative ans
    return solve(nums, target, 0, 0, dp, offset);
}
// another way to remove offset problem, we know that f(index,x)=f(index,-x) for this problem

class Solution
{
public:
    int memo(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (nums[0] == abs(target))
            {
                if (nums[0] == 0)
                {
                    return 2;
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[index][abs(target)] != -1)
        {
            return dp[index][abs(target)];
        }

        int negative = memo(nums, abs(target - nums[index]), index - 1, dp);
        int positive = memo(nums, target + nums[index], index - 1, dp);
        return dp[index][abs(target)] = negative + positive;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        target = abs(target);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return memo(nums, abs(target), nums.size() - 1, dp);
    }
};
