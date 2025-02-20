#include <bits/stdc++.h>
using namespace std;

//T.C O(N*N!) 
//!No duplicates in array
/*
Given an array nums of distinct integers, return all the possible
permutations
You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
*/

/*aproach
we use backtraking,we use a temp vector to store a generating pemutation
if it's  size reaches n, pemutation is generated and pushed in our answer
we use a set to take note of elements which are already used in pemutation(hence can't be used)

at last we pop our element from temp and isUsed set (backtrack) to generate further permutations
*/
class Solution {
    public:
    
    void gen(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,unordered_set<int>isUsed)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
         if(isUsed.find(nums[i])==isUsed.end())//Not found,not used
         {
            temp.push_back(nums[i]);
            isUsed.insert(nums[i]);
            gen(nums,ans,temp,isUsed);
            temp.pop_back();
            isUsed.erase(nums[i]);
         }
        }
    }
    
        vector<vector<int>> permute(vector<int>& nums) 
        {
            unordered_set<int>isUsed;//a unordered_set to track what element is already used in our permutation
            vector<vector<int>>ans;
            vector<int>temp;//when this array reaches n size, it means new pemutation is generated ready to be pushed in ans matrix
            gen(nums,ans,temp,isUsed);
            return ans;
        }
    };