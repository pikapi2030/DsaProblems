#include <bits/stdc++.h>
using namespace std;

// memoisation
//  helper(nums,a,b) tell me that is there any subset in nums array till
//  index a whoose sum is equal to b also my target changes with every
//  recursion as i am not using extra parametre of curSum

bool helper(vector<int> &nums, int index, int target,
            vector<vector<int>> &dp) // doing recursion in a reverse way
{
    if (target == 0)
    {
        return true;
    }
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

bool subsetSumk(vector<int> &nums, int k)
{
    vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
    return helper(nums, nums.size() - 1, k, dp);
}

/*tabulation
since there two changing states in function and we used a 2d dp array we will use two nested
loops for tabulation
we will first set the base cases
*/

bool subsetSumK(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0)); // since we do not need any -1 marking, we can use bool type
    // setting the base case
    for (int index = 0; index < n; index++)
    {
        for (int target = 0; target < k + 1; target++)
        {
            dp[index][0] = true; // if target==0 return true;
        }
    }

    dp[0][nums[0]] = true; // if(index==0){return target==nums[0] }
    // now perform a nested iteration as 2D dp is used
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target < k + 1; target++)
        {
            bool pick = false; // if we do not pick due to target<nums[index], pick should be false
            if (target >= nums[index])
            {
                pick = dp[index - 1][target - nums[index]];
            }
            bool notPick = dp[index - 1][target];

            dp[index][target] = pick || notPick;
        }
    }
    return dp[n-1][k];//intial function call parametres
}
