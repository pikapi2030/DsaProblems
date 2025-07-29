#include <bits/stdc++.h>
using namespace std;
vector<int> smallestSubarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<int> mem(31, -1); // mem[k]= index of number whoose kth bit is set and closest(in right direction) to num[i]
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int j = i;

        for (int ithBit = 0; ithBit <= 31; ithBit++)
        {
            if (!nums[i] & (1 << ithBit)) // if ithBit of nums i is not set, then expand our j till the num[j] whose ith bit is set(will have to thereotically perform OR with this to set ith bit of current num[i] )
            {
                if (mem[ithBit] != -1)
                {
                    j = max(j, mem[ithBit]);
                }
            }
            else
            {
                mem[ithBit] = i; // updated mem array
            }
        }
        ans[i] = j - i + 1;
    }
    return ans;
}