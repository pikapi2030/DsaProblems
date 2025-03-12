#include <bits/stdc++.h>
using namespace std;
/*
given an array, return the number of subsequences with sum k
*/

int helper(vector<int> &v, int k, vector<int> &temp, int index, int sum)
{
    int n = v.size();
    if (index >= n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    temp.push_back(v[index]); // pick
    sum += v[index];
    int pick = helper(v, k, temp, index + 1, sum); // pick call
    temp.pop_back();
    sum -= v[index];
    int notPick = helper(v, k, temp, index + 1, sum); // non pick call
    return notPick + pick;
}

int perfectSum(vector<int> &v, int k)
{
    vector<int> temp;

    return helper(v, k, temp, 0, 0);
}
