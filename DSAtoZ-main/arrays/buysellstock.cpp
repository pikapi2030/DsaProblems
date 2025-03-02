#include <bits/stdc++.h>
using namespace std;

/*
we have been given an array containing value of stock on indexth day
return maximum profit
we cannot sell before buying, and buying and selling can only be performed once
example
arr={7,1,5,3,6,4}
max profit = 6-1=5
we buy on 1th(arr[1]=1) day and sell on 4th day(arr[4]=6)

*/

/*
brute force
T.C O(N^2)
S.C O(1)
*/
int maxprofitbrute(vector<int> v)
{
    int maxp = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] > v[i])
            {
                maxp = max(maxp, v[j] - v[i]);
            }
        }
    }
    return maxp;
}

/*
T.C O(N)
S.C O(1)
we maintain a min=INT_MAX, if v[i]<min then update min, v[i]>min then take
profit and maintain a profit max
return profit max
*/
int maxprofitoptimal(vector<int> v)
{
    int n = v.size();
    int minbuy = INT_MAX;
    int mprofit = 0;
    for (int i = 0; i < n; i++)
    {
        if (minbuy > v[i])
        {
            minbuy = v[i];
        }
        if (minbuy < v[i])
        {
            mprofit = max(mprofit, v[i] - minbuy);
        }
    }
    return mprofit;
}

