#include<bits/stdc++.h>
using namespace std;
/*Q
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the 
index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
 
/*hint
the problem is basically asking for a lower bound

T.C same as BS  O(log_2 N)
*/
class Solution {
public:
    int searchInsert(vector<int>& v, int target)
    {
        int low=0;
        int high=v.size()-1;
        int ans=v.size();
        while(high>=low)
        {
            int mid=low+(high-low)/2;
            if(v[mid]>=target)
            {
                if(target==v[mid]){return mid;}
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
};

