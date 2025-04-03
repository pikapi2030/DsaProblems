#include <bits/stdc++.h>
using namespace std;
/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

*/

/*Brute-aproach
pick-not pick aproach
we will generate all susequences and find the subsequences with sum k
but since we are not allowed to return duplicate subsequences(array contains duplicates so duplicate subsequences are possible)
we will store our subsequences in set instead of an vector of vector
T.C O((2^n)*klog(size of set) )
*/

/*optimal aproach
backtrack on a sorted input array, making sure not to pick same elements(they will be adjacent)
to us as array is sorted
*/
void helper(vector<int> &cand, vector<int> &temp, int target, vector<vector<int>> &ans, int index)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < cand.size(); i++)
    {
        if (i > index && cand[i] == cand[i - 1])
        {
            continue;
        }
        temp.push_back(cand[i]);
        helper(cand, temp, target - cand[i], ans, i + 1);
        temp.pop_back();//backtrack
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> temp;
    vector<vector<int>> ans;
    helper(candidates, temp, target, ans, 0);
    return ans;
}
