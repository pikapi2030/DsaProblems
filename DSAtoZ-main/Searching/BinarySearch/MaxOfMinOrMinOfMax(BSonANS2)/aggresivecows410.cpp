#include <bits/stdc++.h>
using namespace std;
/*
similar to leetcode 1152
given an vector stalls, stall[i] represents position of that stall

we have n number of cows, we have to arrange them such that the minimum distance
between the two cows is maximum

*/

int ispossible(vector<int> &v, int total_COWS, int mindist)
{ // we will place first cow at v[0]
    int n = v.size();
    int cowCount = 1;   // counts number of cows are places
    int lastCOW = v[0]; // keep tracks of where the last cow was placed(stall no)
    for (int i = 1; i < n; i++)
    {
        if (v[i] - lastCOW >= mindist) // therefore cow can be placed at v[i]
        {
            cowCount++;
            lastCOW = v[i];
        }
    }
    if (cowCount >= total_COWS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*BRUTE
we iterte thorugh possible value range of the dist, try to find the max value poosible
to do that we have to right a ispossible function

THE max value of distance between two cows can be (max -min) of stall vector
T.C O(max-min)

*/

int BRUTE(vector<int> &v, int totalCOWS)
{
    sort(v.begin(), v.end());//sorting cause we need min distance to be max, therefore distance between two cows
    int mins = *(min_element(v.begin(), v.end()));//or mins=v[0]
    int maxs = *(max_element(v.begin(), v.end()));//or maxs=v[v.size()-1]
    // i represents our maximum distance we can achieve between two cows (the answer)
    for (int i = 1; i <= maxs - mins; i++)
    {
        if (ispossible(v, totalCOWS, i))
        {
            continue;
        }
        else
        {
            return i - 1; // previous ditance was possible,since at this distance we failed
        }
    }
}

/*OPTIMAL
instead of iterative search, we do BS
since we know range of our ans is 1 to (max-min) of vector v
*/

int opti(vector<int>&v,int TotalCows)
{
    sort(v.begin(),v.end());//sorting cause we need min distance to be max, therefore distance between two cows
    int high=v[v.size()-1]-v[0];//sorted
    int low=1;//min value possible of answer
    while(high>=low)
    {
        int mid=(low+high)/2;
        if(ispossible(v,TotalCows,mid))
        {
          low=mid+1;//we need to maximize the possible dist
        }
        else
        {
            high=mid-1;//dist not possible, reduce value
        }
    }
    return high;//low points to all the posible dist, while to not possible so reverse polarity rule
    

}


