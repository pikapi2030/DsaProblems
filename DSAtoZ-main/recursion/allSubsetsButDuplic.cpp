#include <bits/stdc++.h>
using namespace std;
/*
generate all subsets, input array can contain duplicate elements
*/
class Solution {
    public:
    
    void helper(vector<int>&v,vector<int>&temp,vector<vector<int>>&ans,int index)
    {
    if(index ==v.size())
    {
        return;
    } 
    
    for(int i=index;i<v.size();i++)
    {
        if(i>index&& v[i-1]==v[i])
        {
    continue;
        }
        temp.push_back(v[i]);
        ans.push_back(temp);
        helper(v,temp,ans,i+1);
        temp.pop_back();
    }
    
    }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) 
        {
            sort(nums.begin(),nums.end());
            vector<int>temp;
            vector<vector<int>>ans;
            helper(nums,temp,ans,0);
            ans.push_back({});
            return ans;
        }
    };