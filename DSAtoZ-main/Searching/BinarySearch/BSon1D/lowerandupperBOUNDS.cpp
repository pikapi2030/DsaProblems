#include<bits/stdc++.h>
using namespace std;

/*lower bound algo

array given is sorted
it returns smallest index for a target x such that v[index]>=x
if x is not present in array, it rturns hypothetical index v.size()(return size)
*/

/*
we have low,mid,high pointers and a target and we do somthing similar to BS
we maintain a ans var initialised to v.size()(for target not found)
if v[mid]>=x then update ans=mid and trim our search space
now we need to search a index which is smaller to this mid which fulfills our condtion
to we will bring high to mid-1

if V[mid]<x then we will reduce our search space and bring lefto to mid+1
as we are sure that left of mid cannot contain something greater of equal to x

T.C same as BS
*/

int LB(vector<int>v,int target)
{
    int n=v.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(high>=low)
    {
            int mid=(low+high)/2;

        if(v[mid]>=target)
        {
            ans=mid;
            high=mid-1;
        }
        else 
        {
            low=mid+1;
        }
    }
    return ans;
}

/*LOWER bound function in stl
lower_bound(v.begin(),v.end(),target) return and iterator pointing 
towards lower bound of the target

to get index from the function we can simply subtract v.begin() from the iterator

int lb_index=lower_bound(v.begin(),v.end())-v.begin();

*/


/*upper bound
it is very similar to lb just instead of v[index]>=target where index is smallest possible
it returns index where v[index]>target where index is SMALLEST POSSIBLE
JUST EQUaL SIGHN IS REMOVED
code is similar with equal sighn removed
*/

int UB(vector<int>v,int target)
{
    int n=v.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(high>=low)
    {
            int mid=(low+high)/2;

        if(v[mid]>target)//here is the difference
        {
            ans=mid;
            high=mid-1;
        }
        else//v[mid]<=target 
        {
            low=mid+1;
        }
    }
    return ans;
}

/*LB IN STL
int lb_index=lower_bound(v.begin(),v.end(),target)-v.begin()
*/