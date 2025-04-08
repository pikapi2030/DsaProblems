#include <bits/stdc++.h>
using namespace std;
/*
The XOR total of an array is defined as the bitwise XOR of all its elements,
or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.

Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some
(possibly zero) elements of b.

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6

Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28

Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.

*/

/*aproach 1
generate all subsets and calculate xor
T.C O(n*2^n)  S.C O(N+N)
*/

void gen(vector<int> &v, vector<int> &temp, int &ans, int index)
{
    if (index == v.size())
    {

        return;
    }
    for (int i = index; i < v.size(); i++)
    {

        temp.push_back(v[i]);
        int xors = 0;
        for (auto it : temp)
        {
            xors = (xors ^ it);
        }
        ans += xors;
        gen(v, temp, ans, i + 1);
        temp.pop_back();
    }
}

int BRUTE(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    vector<int> temp;
    gen(nums, temp, ans, 0);
    return ans;
}

/*aproach 2
instead of generating all subsets and storing them, use pick-not pick aproach to
calculate xor on the fly
T.C O(2^N),  S.C O(N) (recusion stack space)
*/

int helper(vector<int> &nums, int ans, int index)
{
    if (index == nums.size())
    {
        return ans;
    }
    int picked = helper(nums, ans ^ nums[index], index + 1);
    int notPick = helper(nums, ans, index + 1);
    return picked + notPick;
}

int Better(vector<int> &nums)
{
    int ans = 0;
    return helper(nums, ans, 0);
}

/*opti 
TAKE OR OF ALL ELEMENTS
APPEND n-1 Zeroes at he back of the result(OR of all elements)
therefore, ans= (OR of all elements)<<n-1  (to append zeores we left shift)
*/