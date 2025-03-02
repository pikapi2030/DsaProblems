#include<bits/stdc++.h>
using namespace std;
/*
given a sorted array, all numbers expect one appear twice, find the single element
using O(log N) T.C

*/

/*
we will use B.S and odd,even indexes of duplicates

if we are on a even index:-
(

 our previous odd index has same element then single element is on our left
 

 if our previous odd element has a different element then single element is on right side
 
)

if we are on a odd index:-
(
 if our previous even element has a different element then single element is on left side
 element

 if our previous even index has same element then single element is on right side
)

also if we are on single element then
v[mid+1]!=v[mid]&&v[mid-1]!=v[mid]

TO EVADE OUT OF BOUNDS ERORR WE check for mid==0 and mid==n seperately 
AND START OUR SEARCH FROM LOW=1 AND HIGH=N-2

IF N(size)==1 RETURN V[0](edge case)

*/
int opti(vector<int>v)
{
int n=v.size();
int ans;

if(n==1)
{
    return v[0];
} 

if(v[0]!=v[1])//checking already since we starting our search from low=1 and high=n-2 to avoid out of bound errors
{
    return v[0];
}
if(v[n-1]!=v[n-2])
{
    return v[n-1];
}
int low=1,high=n-2;
while(high>=low)
{
    int mid=(low+high)/2;

    if(v[mid+1]!=v[mid]&&v[mid-1]!=v[mid])
    {
         ans=v[mid];
        break;
    }

    if(mid%2==0)//on even index
    {
       if(v[mid-1]!=v[mid])//eliminate left
       {
        low=mid+1;
       }
       else
       {
        high=mid-1;
       }
    }
    else//mid is odd
    {
           if(v[mid-1]==v[mid])//eliminate left
       {
        low=mid+1;
       }
       else
       {
        high=mid-1;
       }

    }
}
return ans;

}
