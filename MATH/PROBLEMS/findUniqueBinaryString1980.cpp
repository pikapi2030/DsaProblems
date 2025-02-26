#include <bits/stdc++.h>
using namespace std;
/*
Given an array of strings nums containing n unique binary strings each of length n, 
return a binary string of length n that does not appear in nums. If there are multiple answers,
you may return any of them.
*/

/*aproach: using contors diagonal proof( which prooves that real numbers are uncountable)
T.C O(n) S.C O(1)
*/

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



