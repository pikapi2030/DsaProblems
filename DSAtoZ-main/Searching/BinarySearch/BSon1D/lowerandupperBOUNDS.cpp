#include<bits/stdc++.h>
using namespace std;

/*lower bound algo

std::lower_bound is a Standard Template Library (STL) algorithm used to find the 
first position where a given value can be inserted in a sorted range without 
violating the order. In simple terms, it returns an iterator pointing to the first 
element that is greater than or equal to (>=) the given value.
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
upper_bound is a Standard Template Library (STL) function used to find the first element 
that is strictly greater than a given value in a sorted range. It is commonly used for 
efficient searching and range queries in sorted containers.*/

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