#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums. You are initially positioned at the array's first index,
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0,
which makes it impossible to reach the last index.

*/

/*aproach
we initialise a max index, which indicates max index reachable
if travese through array, if current index is reachable we update our maxIndex
if maxIndex becomes more than size, we return true
*/
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxIndex = 0; // max index reachable currently
    for (int i = 0; i < n; i++)
    {
        if (maxIndex >= nums.size() - 1)
        {
            return true;
        }
        if (maxIndex >= i)
        {
            maxIndex = max(maxIndex, i + nums[i]);
        }
    }
    if (maxIndex >= nums.size() - 1)
    {
        return true;
    }
    return false;
}
