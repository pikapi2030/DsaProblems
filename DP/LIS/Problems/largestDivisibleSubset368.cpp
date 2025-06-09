#include <vector>
#include <algorithm>
using namespace std;
/*
Given a set of distinct positive integers nums, return the largest subset answer such that
every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/
vector<int> largestDivisibleSubset(vector<int> &v)
{

    int maxLen = 1;
    int lastIndex = -1;
    int n = v.size();
    if (n == 1)
    {
        return v;
    }
    sort(v.begin(), v.end()); // since v[i]%v[j] OR v[j]%v[i] are accepted, order of elements does not matter
    vector<int> dp(n, 1);
    vector<int> hash(n, -1);
    for (int i = 1; i < n; i++)
    {
        for (int pi = 0; pi < i; pi++)
        {
            if (v[i] % v[pi] == 0 && dp[pi] + 1 > dp[i])
            {
                dp[i] = dp[pi] + 1;
                hash[i] = pi;
            }
        }
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            lastIndex = i;
        }
    }
    if (lastIndex == -1)
    {
        return {v[0]};
    } // LIS is the elemnts of v[i] itself, choose any(I choose 0 indexed as safest)
    // printing
    vector<int> ans;
    while (hash[lastIndex] != -1)
    {
        ans.push_back(v[lastIndex]);
        lastIndex = hash[lastIndex];
    }
    ans.push_back(v[lastIndex]);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> v = {3, 4, 16, 8};
    largestDivisibleSubset(v);
}
