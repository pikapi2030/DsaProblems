#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet,
 you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom
 in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able
to make m bouquets from the garden. If it is impossible to make m bouquets return -1.



Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means
flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers.
We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot
 make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

*/

long long maxOFaVector(vector<int> v)

{
    long long max = LONG_LONG_MIN;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*(it) > max)
        {
            max = *(it);
        }
    }
    return max;
}

long long minOFavector(vector<int> v)
{
    long long min = LONG_LONG_MAX;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (min > *(it))
        {
            min = *(it);
        }
    }
    return min;
}

int ispossible(int m, int k, int day, vector<int> v) // a function to check if m bouques are possible on a particular day
{
    long long cnt = 0; // to count consecutive number of bloomed flowers
    long long num_of_bouque = 0;
    long long n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (day >= v[i]) // means flower has bloomed
        {
            cnt++;
        }
        else // an unbloomed flower breaks the consecutiveness, we check if any bouquet till now is possible
        {
            num_of_bouque += (cnt / k); // k adjacent flower to make one boque, so total adjacent flower/k=num of boque
            cnt = 0;                    // setting it 0 as we are counting consecutives
        }
    }
    num_of_bouque += cnt / k; // final check,as else wont run if last index is bloomed already

    if (m <= num_of_bouque)
    {
        return 1; // m bouque possible
    }
    else
    {
        return 0;
    }
}

/*BRUTE
the range of loop space from min of vector to max of vector
we make a function to check possibility on that day, if possible
we return as we iterate from min to max so first day possible will be min

T.C O((d+1)*n) where d is the difference between max and min
(we ingnored T.C due to max and min functions)
*/

int BRUTE(vector<int> &v, int m, int k)
{

    long long max = maxOFaVector(v);
    long long min = minOFavector(v);
    for (int i = min; i <= max; i++)
    {
        if (ispossible(m, k, i, v))
        {
            return i;
        }
    }
    return -1;
}

/*OPTIMAL 
we know the range of search space, we know if is possible=1 on that day we eliminate
right to get min day, if not we eliminate left to get a possible day

our low will be always pointing to ans at the end of loop as at start it was pointing to 
no possible days and our high was pointing to possible days

T.C O(N*LOG_2 d+1) d=max-min
*/

int OPTIMAL(vector<int>v,int m,int k)
{
    long long low=minOFavector(v);
    long long high=maxOFaVector(v);
            if(m*k>v.size())//use m>v.size()/k to prevent overflow
        {
            return -1;
        }

    while(high>=low)
    {
        long long mid=(high+low)/2;
        
        if(ispossible(m,k,mid,v))//it is possible so reduce the day(eliminate right space)
        {
         high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    
    }
    return (int)low;/*low at the end wil always point to minimum day as it start from not 
    possible days and high starts from possible days to there 
    polarity is reversed(BS RULE)*/

}
