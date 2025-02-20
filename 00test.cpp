#include <bits/stdc++.h>
using namespace std;
string findDifferentBinaryString(vector<string>& nums) 
{
string ans;
int n=nums.size();
int j=0;
for(int i=0;i<n;i++)
{
   if(nums[i][i]=='1')
   {
    ans.push_back('0');
   }
   else if(nums[i][i]=='0')
   {
    ans.push_back('1');
   }   
   
}    
 return ans;
}
