#include <bits/stdc++.h>
using namespace std;
//! duplicate allowed
/*
Given a collection of numbers, nums, that might contain duplicates,
return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

/*aproach
we will use same aproach as permutation I, but duplicates are allowed so we will use
a hashmap to take account of frequency of our element so that we can consider it in our
permutation even it is already used(it's duplicate is used, so we can use it again)

//!we will traverse the map instead of array as travesing array will create redundant
//! iterations and copies of already push_backed temp, making our answer incorrect

*/

void gen(vector<int> nums, map<int, int> &mp, vector<int> &temp, vector<vector<int>> &ans)
{
    if (temp.size() == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    for(auto &it:mp)//!!if we iterate array then it creates duplicate pemurations, also redundant iterations
    {
        int element=it.first;
        int frequency=it.second;
        if(frequency!=0)//elements left to be used
        {
            temp.push_back(element);
            mp[element]--;//element used, reducing frequency
            gen(nums,mp,temp,ans);
            //!now backtrack
            temp.pop_back();
            mp[element]++;
        }
    }
}

vector<vector<int>> Pemutations(vector<int> nums)
{
    map<int, int> mp; // building a hashmap
    for (auto it : nums)
    {
        mp[it]++;
    }
    vector<int> temp;
    vector<vector<int>> ans;
    gen(nums, mp, temp, ans);
    return ans;
}
