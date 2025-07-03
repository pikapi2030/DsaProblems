#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &height)
    {
        int n = height.size();
        int m = height[0].size();
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        vector<vector<int>> minEff(n, vector<int>(m, INT_MAX));
        //{max_effort_to_reach_this_cell_from_source,{row,col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int CurrEff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
                {
                    int neighbourCellEff = max(abs(height[nrow][ncol] - height[row][col]), CurrEff);
                    if (neighbourCellEff < minEff[nrow][ncol]) // better way to reach (nrow,ncol)
                    {
                        minEff[nrow][ncol] = neighbourCellEff;
                        pq.push({neighbourCellEff, {nrow, ncol}});
                    }
                }
            }
        }
        return minEff[n - 1][m - 1];
        // COPIDED
    }
};