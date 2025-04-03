#include <bits/stdc++.h>
using namespace std;
/*
Given an array of distinct integers candidates and a target integer target, return a 
list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the

of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to 
target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []

*/

/*aproach
we will use the pick-not pick apraoch but we will not move to the next index until our
target-(sum of all picked elements) is not 0 or negative, as we can pick a element infinite 
times
*/

void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, int index, vector<int>& temp, int curSum)
{
    if (curSum == target)  // If we achieve target, store the result
    {
        ans.push_back(temp);
        return;
    }

    if (index == candidates.size() || curSum > target)  // Base case: Stop when out of bounds or sum exceeded
        return;

    // Pick the current element
    temp.push_back(candidates[index]);
    helper(candidates, target, ans, index, temp, curSum + candidates[index]);
    temp.pop_back(); // Undo the pick (backtracking)

    // Move to the next index (Not pick)
    helper(candidates, target, ans, index + 1, temp, curSum);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(candidates, target, ans, 0, temp, 0);
    return ans;        
}

