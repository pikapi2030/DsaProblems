#include<bits/stdc++.h>
using namespace std;
/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays 
such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
quetion similar to allocation of books
nums can be considered book array
k can be number of children
sum can be number of pages alloted
*/

/*opti
we will use BS
we know range ans= maxof array to sum of array
so we use BS and we eliminate on basis of how many splits does our current ans need
if the number of splits are less than k then this means limit is too much(sum of subarray)
so we eliminate right half
if splits==k then it might be a possible ans but we want to minimize our limit(sum)
so we still eliminate right half
if splits>k then limit is too less(sum of subarray) and we need to eliminate left half

to calculate number of splits we use a function
*/

int NumberOfSplits(vector<int>v,int limit)//limit means allowed sum upper limit
{
  int CurrentSum=0;
  int num_of_split=1;
  
  for(int i=0;i<v.size();i++)
  if(v[i]+CurrentSum<=limit)
  {
    CurrentSum+=v[i];
  }
  else
  {
    num_of_split++;
    CurrentSum=v[i];
  }
  return num_of_split;
}

int optimal(vector<int>v,int splitsToBeMade)
{
long long low=*(max_element(v.begin(),v.end()));
long long high=accumulate(v.begin(),v.end(),0);//to calculate sum

while (high>=low)
{
    long long mid=(low+high)/2;
    if(splitsToBeMade>=NumberOfSplits(v,mid))//less splits than needed, reduce the total sum aka limit
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
}
return (int)low;//at end of loop low will point to ans polarity rule
}

