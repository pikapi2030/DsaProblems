#include <bits/stdc++.h>
using namespace std;
/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day,
 we load the ship with packages on the conveyor belt (in the order given by weights).
 We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on
the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14
and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is
not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

*/

/*
we have a vector with various loads writte on its indexes
our ship nedd to carry all of it to other side, 
it can load multiple indexes at once(if capacity is not exceded)
but each index cannot be broken ito smaller loads


*/

long long maxOFaVector(vector<int> v)

{
    long long max = LONG_LONG_MIN;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*(it) > max)
        {
            max = *(it);
        }
    }
    return max;
}
long long sumOFvector(vector<int>v)
{
    int sum=0;
       for (auto it = v.begin(); it != v.end(); it++)
    {
        sum+=*(it);
    }
    return sum;
 
}

long long daysrequired(vector<int>v,int cap)
{
    long long currentLoad=0;
    long long  daysRequired=1;
    for(int i=0;i<v.size();i++)
    {
     if(currentLoad+v[i]>cap)/*capacity exceeded ship releses all load, 
     and came back to load v[i] and others to go back again if this condition hits*/
     {
      daysRequired++;
      currentLoad=v[i];
     }
     else
     {
        currentLoad+=v[i];
     }
    }
    return daysRequired;
}
/*BRUTE SOLUTION
we can think that our min cap of ship need to be equal to max of v to load that load in our ship
if it is less than our ship will not be able to go(our ship can go only if ith index is fully )
max can be sum of total load, if we have max cap than our ship can do all loading in one day
(will take all the loads in one go as cap is equal to sum of all the loads)

so our loop space of cap is from max of v to sum of v
we will find for each cap if dayallowed>=days taken if yes then we will return it
T.C O(sum-maxofvector+1)*N  (ignored small fuctions T.C)
*/

int BRUTE(vector<int>v,int days_allowed)
{
    for(int cap=maxOFaVector(v);cap<=sumOFvector(v);cap++)
    {
        long long days_needed=daysrequired(v,cap);
        if(days_needed<=days_allowed)
        {
            return cap;
        }
    }
    return -1;
}

/*OPTI
we know the search space range so use BS

*/

int optimal(vector<int>v,int days_allowed)
{
    long long low=maxOFaVector(v),high=sumOFvector(v);
    while(high>=low)
    {
        long long mid=(low+high)/2;
        int daysTaken=daysrequired(v,mid);
        if(daysTaken<=days_allowed)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        
    }
    return low;

}
