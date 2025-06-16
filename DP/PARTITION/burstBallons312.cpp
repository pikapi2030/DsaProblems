#include <bits/stdc++.h>
using namespace std;
/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on
it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon
with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.
Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:
Input: nums = [1,5]
Output: 10
*/

/*approach
instead of solving it in forward order, we will solve it in revere order
( we will decide which balloon to burst last, then second last and so on)
this way we get independent sub problems
//!we also add 1 to start and end of the array
F(start,end)
{
for(ind:-start->end)//ind is index of balloon to be burst from reverse order
{
coins= v[start-1]*v[end+1]+F(start,ind-1)+F(ind+1,end) //do a dry run, this formula will make
sense
minimize the coins
}
}

*/

int rec(vector<int> &v, int start, int end)
{
    int maxi = 0;
    if (start > end)
    {
        return 0;
    }
    for (int ind = start; ind <= end; ind++)
    {
        int coins = v[start - 1] * v[end + 1] * v[ind] + rec(v, start, ind - 1) + rec(v, ind + 1, end);
        maxi = max(maxi, coins);
    }
    return maxi;
}

int brute(vector<int> &v)
{
    v.insert(v.begin(), 1);
    v.push_back(1);
    int n = v.size();
    return rec(v, 1, n - 2);
}

// tabulation

