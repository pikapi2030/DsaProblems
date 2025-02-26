#include <bits/stdc++.h>
using namespace std;
/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is
the start time of meeting i and end[i] is the finish time of meeting i.
Return the maximum number of meetings that can be accommodated in a single meeting room,
when only one meeting can be held in the meeting room at a particular time.

Note: The start time of one chosen meeting can't be equal to the end time of the other
chosen meeting.
*/

/*greedy aproach  T.C O(NlogN) S.C O(n)(making pairs)
we make pairs and sort them according to end time, we always perform the first meeting
store the lastMettingEndingTime, if it is less than next meetings start, we perform
it and update our lastMeetingEndTime 
*/
static bool comp(pair<int, int> a, pair<int, int> b)
{
    return b.second > a.second;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int cnt = 1;                     // will always perform the first meeting
    vector<pair<int, int>> combined; //{start,end}
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        combined.push_back({start[i], end[i]});
    }
    sort(combined.begin(), combined.end(), comp);
    int lastMeetingEndTime = combined[0].second; // first meeting is held

    for (int i = 1; i < n; i++)
    {
        if (lastMeetingEndTime < combined[i].first) // perform the meeting
        {
            lastMeetingEndTime = combined[i].second;
            cnt++;
        }
    }
    return cnt;
}
