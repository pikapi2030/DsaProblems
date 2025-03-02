#include <bits/stdc++.h>
using namespace std;
/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

/*BRUTE

uses two nested forloops(still T.C(due to loops) is O(2N) due to countinue and break)

we sort the given list of list
then we traverse it using i
 for each i we traverse from j+1 to n
 we check if our v[i](assume it a list) overlaps
 v[j] by checking the ends if it does then we update end
 of our v[i] to max(end of v[i],end of v[j]) to make sure
 they are properly merged

  also if the two intervals do not overlap than no need to check further as array is sorted
  so no further overlaping wiil happen(end of v[i] wil be smaller then end of v[j] )

 also before entering the inner loop we check if our current v[i] is already
 a part (subset) of last interval present in ans array
 (if it is then no need to check for v[i])

T.C O(2N+NlogN)
S.C O(N)

*/
vector<vector<int>> BRUTE(vector<vector<int>> v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = v[i][0];
        int end = v[i][1];
        if (!ans.empty() && end <= ans.back()[1]) // ans.back() return last element of ans,
        // ans().back[1] means end of last elemenrt of ans
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (end >= v[j][0])
            {
                end = max(end, v[j][1]); // merging
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

/*OPTIMAL
uses one loop
we make an ans nested vector
we sort our input
we check if our ans array is empty then we need to add v[i] interval
if not empty we compare end of last element of ans array and start element of v[i]
if ans.back()[1](end of last element of answer array)
is greater than start of v[i] then there is over lap
if not no overlap

if no overlap, we simply add the interval

T.C NlogN(sorting)+O(N)(loop)
S.C O(N)

*/
vector<vector<int>> opti(vector<vector<int>> &v)
{

    vector<vector<int>> ans;
    sort(v.begin(), v.end());

    int n = v.size();
    for (int i = 0; i < n ; i++)
    {
        {
            if (ans.empty() || v[i][0] > ans.back()[1])
            {
                ans.push_back(v[i]); // pushbacking first interval and interval that do not overlap
            }
            else
            {
               ans.back()[1]=max(ans.back()[1],v[i][1]);
            }
        }
    }
    return ans;
}

// mys sol gives wrong answers due to erase and resize of vector v(resizing vector causing loop prolems)
vector<vector<int>> mysol(vector<vector<int>> &v)
{

    sort(v.begin(), v.end());

    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        {
            if (v[i][1] >= v[i + 1][0])
            {
                v[i][1] = max(v[i + 1][1], v[i][1]);
                v.erase(v.begin() + i + 1, v.begin() + i + 2);
                n = v.size();
            }
        }
    }
    return v;
}