#include <bits/stdc++.h>
using namespace std;
/*
Given an
long longeger array nums, in which exactly two elements appear only once and all the other
elements appear exactly twice. Find the two elements that appear only once. You can return
the answer in any order. You must write an algorithm that runs in linear runtime complexity
and uses only constant extra space.
Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:
Input: nums = [-1,0]
Output: [-1,0]
Example 3:
Input: nums = [0,1]
Output: [1,0]
*/

/*approach
xor all numbers, lets call it finalXor , the finalxor will be xor of the two diffrenet numbers
occuring one time
we need to from two groups, such that these two numbers go in two different groups
if we succeed in that then we can simply xor the elements of each groups with itself
to get the two numbers as we know other members of the group will be duplicte

be will seperate the two numbers  on the basis of first rightmost different bit between the
two numbers
the first different rightmost bit between two numbers is first set bit of xor of them
*/
vector<long long>
singleNumber(vector< long long> &v)
{

    long long finalXor = 0;
    for (
        long long it : v)
    {
        finalXor = finalXor ^ it;
    }

    long long rightMostDifferentBit = (finalXor & finalXor - 1) ^ finalXor; // just extracting right most bit of finalXor

    long long g1 = 0, g2 = 0;
    for (
        long long it : v)
    {
        if (rightMostDifferentBit & it)
        {
            g1 = g1 ^ it;
        }
        else
        {
            g2 = g2 ^ it;
        }
    }
    return {g1, g2};
}
