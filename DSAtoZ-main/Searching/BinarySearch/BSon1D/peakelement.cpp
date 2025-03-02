#include<bits/stdc++.h>
using namespace std;
/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is 
always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
*/

/*BRUTE (not coded)
using for loop, O(N)
*/

/*opti
(duplictes are not present)
since we can return any peak,we will use binary search

let's assume there is only one peak

we can check if our mid is peak or not 
if our mid is not peak then 

if our mid is on the increasing line then peak is on the right
so if(v[mid]>v[mid-1]) then eliminate left

if our mid is on decreasing line then peak is on the left 
that means if (v[mid+1]<v[mid]) so eliminate right

we will make seperate cases of
 n==1(one size array)

v[0] and v[n-1] and start our search from low=1 to high=n-2(to prevent run time error)

SINCE WE HAVE TO RETURN ANY OF THE ONE PEAK, WE CAN IGNORE ALL OTHER PEAKS AND THIS CODE WILL
STILL WORK(we have to take care when mid is on local minima of the values )


*/

int optipeak(vector<int>v)
{
    int n=v.size();
    
    if(n==1)
    {
        return 0;//return index
    }
    if(v[0]>v[1])
    {
        return 0;
    }
    if(v[n-1]>v[n-2])
    {
        return n-1;
    }

    int low=1,high=n-2;//trimmed search

    while(high>=low)
    {
        int mid=(low+high)/2;
        if(v[mid]>v[mid+1]&&v[mid]>v[mid-1])
        {
            return mid;
        }
        
        else if(v[mid]>v[mid+1])//decreasing slope
        {
            high=mid-1;//eliminate right
        }
        else//handles both minima case on slope increasing case
        //in minima case we can eliminate either of the halves
        {
            low=mid+1;
        }


    }
    return -1;//for int return type(condition returns are not considered)

}

