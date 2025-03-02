#include <bits/stdc++.h>
using namespace std;

int bestDayToBuySell(vector<int> stocks, int low, int high)
{
    int mid = (low + high) / 2;
    int left = low;
    int right = mid + 1;
    int leftMin = INT_MAX;
    int rightMax = INT_MIN;
    while (left <= mid)
    {
        leftMin = min(leftMin, stocks[left]);
        left++;
    }
    while (right <= high)
    {
        rightMax = max(rightMax, stocks[right]);
        right++;
    }

    return rightMax - leftMin;
}

int divider(vector<int> stocks, int low, int high)
{
    int ans = 0;
    if (high <= low)
    {
        return 0;
    }
    int mid = (low + high) / 2;
    int ans1 = divider(stocks, low, mid);
    int ans2 = divider(stocks, mid + 1, high);

    ans = max({ans, bestDayToBuySell(stocks, low, high),ans1,ans2});
    return ans;
}
int main()
{
    vector<int> v = {10, 18, 26, 31, 4, 53, 69};
    cout << divider(v, 0, v.size() - 1);
}
