#include <bits/stdc++.h>
using namespace std;

/*
we have an array p, where p[i]  indicates number of bananas on index i

we have to choose min value of k, where k is number of banana eaten per hour
such that all bananas of all piles are finished in less than or equal to h hours

NOTE: if our speed is 2 banana/hour than a pile with 3 banana will be finished in 2 hours

it should be 1.5 hour but we take the ciel value

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4  ( 1+2+2+3 )
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


*/

/*BRUTE
max k is max of p[i]  as more than that will result in same number of hours taken

Input: piles = [30,11,23,4,20], h = 6
for k=30 we eat bananas in (1+1+1+1+1)=5 hours
for k=31,32,...INT_MAX we eat banana in 5 hours as well



we iterate value of k from 1 to max value of p[i]

if hours taken == h, we return k
*/

int maxOFaVector(vector<int> v)

{
    int max = INT_MIN;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*(it) > max)
        {
            max = *(it);
        }
    }
    return max;
}

int hourstaken(vector<int> p, int k)
{
    long long n = p.size();
    long long hour_Taken = 0;
    for (int i = 0; i < n; i++)
    {
        hour_Taken+=ceil( (double)p[i]/(double)k );//convertinf to double as int/int gives int
        //and ceil of int is the same int so we need to deal in decimals
    }
    return hour_Taken;
}

/*BRUTE
we run loop of k from 1 to max element in p
we calculate hours taken by a function
since we going from 1 to max value of k
the first k to satisfy the condition will be minimum hence our
answer
condition if hourstaken for that k <=h

T.C O(max of p*n)
n is size of p

*/

int brute(vector<int> p, int h)
{

    for (int k = 1; k <= maxOFaVector(p); k++)
    {
        int hour = hourstaken(p, k);
        if (hour <= h)
        {
            return k;
        }
    }
}

int mysol(vector<int> p, int h)
{

    long long low = 1, high = maxOFaVector(p);

    while (high >= low)
    {
        long long mid = (low + high) / 2;
        long long hour = hourstaken(p, mid);

        if (hour <= h) // possible ans but k might not be min, eliminating right space as we need smaller k
        {
            high = mid - 1;
            //I have used low a an answer var, at the end it will automatically point to ans
            //so not doing any returns here
        }
        else // h>hour  k is too less
        {
            low = mid + 1;
        }
    }
    return low;
    /*WHY RETURNED LOW???
    BECAUSE AT START HIGH WAS POINTING AT POSSIBLE ANSWERS AND LOW AT NOT POSSIBLE
    ANSWERS, AT THE END, LOOP WILL ONLY END WHEN POLARITY OF BOTH HIGH AND LOW
    REVERSES, LOW POINT AT POSSIBLE ANS,HIGH AT NOT POSSIBLE ANS
    THIS IS RULE OF BS, AND I COULD HAVE USED AN ANS VARIABLE TO MAKE IT SIMPLER
    WHCIH I WAS ALREADY DOING IN PREVIOUS QUETIONS
    */
}
