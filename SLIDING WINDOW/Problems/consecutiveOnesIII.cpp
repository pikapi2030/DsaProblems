#include <bits/stdc++.h>
using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in
the array if you can flip at most k 0's.
*/
/*sliding window
we have to make sure that our window never have more than k zeroes(k zeroes are flippable to 1)
T.C O(2N)  S.C O(1)
*/

int better(vector<int> &nums, int k)
{
    int ans = 0;
    int n = nums.size();
    int cnt = 0; // counts number of zeroes in our current window
    int left = 0, right = 0;
    while (n > right)
    {
        if (nums[right] == 0)
        {
            cnt++;
        }

        while (cnt > k) // move left window such that numb of zeroes becomes less than k
        {

            if (nums[left] == 0)
            {
                cnt--;
            }
            left++;
        }

        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

// optimal T.C  O(N)  S.C O(1)
/*we still use sliding window but we do not shrink the window,
lets say till now maxlen is 5, shrinking the window will not change the ans as
we are calculating max any way so there is not point to shrink the window
instead of that, when cnt>k we will move left++ and right++ at same time untill
cnt<=k, we wiil update ans only when cnt<=k
*/
int optimal(vector<int> &nums, int k)
{
    int ans = 0;
    int n = nums.size();
    int cnt = 0; // counts number of zeroes in our current window
    int left = 0, right = 0;
    while (n > right)
    {
        if (nums[right] == 0)
        {
            cnt++;
        }
        if (cnt > k)
        {
            if (nums[left] == 0)
            {
                cnt--;
            }
            left++;
        }
        if (cnt <= k)
        {
            ans = max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
}
