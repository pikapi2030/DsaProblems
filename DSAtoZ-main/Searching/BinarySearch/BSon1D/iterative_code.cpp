#include<bits/stdc++.h>
using namespace std;
/*
it is a technique to find index of a target in an sorted array
we reduce our search space to improve T.C
we use three pointers low,mid and high

between low and high is our search space and mid=low+high/2
if our mid points to target then return mid
if mid points to num greater than target , reduce search space(we know our target must be  
present left of mid ) so we move our high pointer to mid-1
if mid points to num less than target then we sure target will be at right side of mid
so we move our low pointer to mid+1 and countinue our search

if low>high(then no search space left return -1(means target is not present))

T.C  O(log_2 (N))  log base 2 N

*/

/*OVERFLOW CASE
if our high=INT_MAX then (low+INT_MAX)/2 gives overflow error

use long long for high and low  to solve this issue
OR
right mid = low+(high-low)/2 (mathematically gives same value as (low+high)/2)
prevents overflow by doing (high-low)/2+low  

*/

int BS(vector<int>v,int target)
{
    int n=v.size();
    int low=0,high=n-1;
    int mid=(low+high)/2;

    while(high>=low)
    {
        if(v[mid]==target)
        {
            return mid;
        }
        else if( v[mid]>target )
        {
            high=mid-1;
        }
        else//v[mid]<target
        {
          low =mid+1;
        }
        mid=(low+high)/2;
    }
    return -1;

}
