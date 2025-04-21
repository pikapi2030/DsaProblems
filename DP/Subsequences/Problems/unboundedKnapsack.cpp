#include <bits/stdc++.h>
using namespace std;
/*
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity
‘w’.
You need to fill the knapsack with the items in such a way that you get the maximum profit.
You are allowed to take one item multiple times.
*/

int recur(vector<int> &prof, vector<int> &w, int cap, int index)
{
    if (cap == 0)
    {
        return 0;
    }
    if (index == 0)
    {
        return (cap / w[0]) * prof[0];
    }
    int pick = 0;
    if (cap >= w[index])
    {
        pick = prof[index] + recur(prof, w, cap - w[index], index);
    }
    int notPick = recur(prof, w, cap, index - 1);
    return max(pick, notPick);
}

int unboundedKnapsack(int n, int cap, vector<int> &profit, vector<int> &weight)
{
    return recur(profit, weight, cap, n - 1);
}
// space optimisation (leaving memoisation and tabulation cause why not?)( using 2 arrays)

int twoArraySpace(int n, int cap, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(cap + 1, 0);
    vector<int> cur(cap + 1, 0);
    for (int capi = 0; capi <= cap; capi++)
    {
        prev[capi] = (capi / weight[0]) * profit[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int capi = 1; capi <= cap; capi++)
        {
            int pick = 0;
            if (capi >= weight[index])
            {
                pick = profit[index] + cur[capi - weight[index]];
            }
            int notPick = prev[capi];
            cur[capi] = max(pick, notPick);
        }
        prev = cur;
    }
    return prev[cap];
}
// space optimisation(only one array)
/*aproach
to compute cur[i], we need prev[i](notPick) and cur[i-w[index]](pick)
so we need previous values of cur array and one single value of prev array
so what we will do is, over write my prev array as a curr array while travesing the prev
array
example prev={1,2,3,4}, travesing prev array
let's say cur[0]=10(to calculate this We need prev[0] as well), we update(over write on prev array),
prev={10,2,3,4} now to calculate cur[1] we need prev[1] and cur[0](assume i-w[index]=0)
we have cur[0] as prev[0] and we also have prev[1], after calculating we get cur[1]=25(assume)
we update our prev array, prev={    10  , 23 ,    3,       4 }
                                    ↑      ↑      ↑        ↑
                                cur[0]    cur[1]  prev[2]  prev[3]
we keep doing this and return nameOfarray[amount] as answer
*/

int OneArraySpace(int n, int cap, vector<int> &profit, vector<int> &weight)
{
    vector<int> prevAndCur(cap + 1, 0);
    for (int capi = 0; capi <= cap; capi++)
    {
        prevAndCur[capi] = (capi / weight[0]) * profit[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int capi = 1; capi <= cap; capi++)
        {
            int pick = 0;
            if (capi >= weight[index])
            {
                pick = profit[index] + prevAndCur[capi - weight[index]];
            }
            int notPick = prevAndCur[capi];
            prevAndCur[capi] = max(pick, notPick);
        }
    }
    return prevAndCur[cap];
}
