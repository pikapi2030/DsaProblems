#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, return true if you can partition the
array into two subsets such that the sum of the elements in both
subsets is equal or false otherwise.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/

/*aproach
solved using pick not pick aproach( both forward and backward recursion possible)
then applied 2d DP as two parametres index and target determine the function call
*/

// FORWARD way recursion CALL
class Solution
{
public:
    bool helper(vector<int> &v, int index, int targetSum, int curSum, vector<vector<int>> &dp)
    {
        if (index == v.size())
        {
            return targetSum == curSum;
        }
        if (dp[index][curSum] != -1)
        {
            return dp[index][curSum];
        }
        bool pick = false;
        if (targetSum >= curSum + v[index])
        {
            pick = helper(v, index + 1, targetSum, curSum + v[index], dp);
        }
        bool notPick = helper(v, index + 1, targetSum, curSum, dp);
        return dp[index][curSum] = pick | notPick;
    }

    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (auto it : nums)
        {
            totalSum += it;
        }
        if (totalSum % 2 != 0)
        {
            return false;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(totalSum / 2 + 1, -1));
        // find such a subset whose sum is equal to totalSum/2 and size is also half
        return helper(nums, 0, totalSum / 2, 0, dp);
    }
};

// backward way recursion call(more intiutive)
class Solution
{
public:
    // helper(nums,a,b) tell me that is there any subset in nums array till
    // index a whoose sum is equal to b also my target changes with every
    // recursion as i am not using extra parametre of curSum

    bool helper(vector<int> &nums, int index, int target,
                vector<vector<int>> &dp) // doing recursion in a reverse way
    {
        if(target==0){return true;}
        if (index == 0)
        {
            return target == nums[0]; // base case ,  to get a subset sum of
                                      // target(which is curSum) till 0th index
                                      // is only possible if nums[0]==target
            // here target is not actual target given initially but actually
            // curSum as i am modifying my target after picking in parametre
            // itself
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        bool pick = false; // if we do not pick due to target<nums[index], pick
                           // should be false
        if (target >= nums[index])
        {
            pick = helper(nums, index - 1, target - nums[index], dp);
        }
        bool notPick = helper(nums, index - 1, target, dp);

        return dp[index][target] = pick | notPick;
    }

    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        for (auto it : nums)
        {
            total += it;
        }
        if (total % 2 != 0)
        {
            return false;
        }
        vector<vector<int>> dp(nums.size() , vector<int>(total / 2 + 1, -1));
        return helper(nums, nums.size() - 1, total / 2, dp); // trying to find a subset with target sum of total
                                                             // sum/2, if it exists our array can be parted
    }
};
