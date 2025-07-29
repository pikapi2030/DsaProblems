#include <bits/stdc++.h>
using namespace std;
/*
Find the longest continuous sub array that has at most k distinct elements
*/

/*sliding window T.C O(2*N)
we maintain a sliding window with max distinct element =2, to do that we use a hash map
to keep track of elements in our window
*/

int better(vector<int> &fruits,int k)
{
    int ans = 0;

    int n = fruits.size();
    map<int, int> mp;
    int left = 0, right = 0;
    while (right < n)
    {
        mp[fruits[right]]++;
        while (mp.size() > k)
        {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0)
            {
                mp.erase(fruits[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

// optimal sliding window T.C O(N) S.C O(1)
/*
we still use sliding window but we do not shrink the window,
lets say till now maxlen is 5, shrinking the window will not change the ans as
we are calculating max any way so there is not point to shrink the window
instead of that, when cntDisticnt>k we will move left++ and right++ at same time untill
cntDistinct<=2, we wiil update ans only when cntDistinct<=k
*/
int optimal(vector<int> &fruits,int k)
{
    int ans = 0;

    int n = fruits.size();
    map<int, int> mp;
    int left = 0, right = 0;
    while (right < n)
    {
        mp[fruits[right]]++;
        if (mp.size() > k)
        {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0)
            {
                mp.erase(fruits[left]);
            }
            left++;
        }
        if (mp.size() <= k)
        {
            ans = max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
}
