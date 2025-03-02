#include <bits/stdc++.h>
using namespace std;
/*
Given an array of intervals intervals where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of the intervals
non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and
[2, 3] are non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

/*aproach
this problem is similar to N meeting in room, we have to decide which meeting not to organise
*/

static bool comp(vector<int>a, vector<int> b)
{
    return  a[1]<b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n=intervals.size();
    sort(intervals.begin(), intervals.end(), comp);
    int maxMeetingPossible = 1;
    int lastMeetingEndTime = intervals[0][1];
    for (auto it : intervals)
    {
        int endTime = it[1];
        int startTime = it[0];
        if (startTime >= lastMeetingEndTime)
        {
            maxMeetingPossible++;
            lastMeetingEndTime = endTime;
        }
    }
    return n-maxMeetingPossible;//these are the number of meeting we could not held(intervals erased)
}