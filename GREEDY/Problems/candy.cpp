#include <bits/stdc++.h>
using namespace std;
/*
There are n children standing in a line. Each child is assigned a rating value given in the
integer array ratings.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies
respectively.

Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies
respectively.
The third child gets 1 candy because it satisfies the above two conditions.

*/

/*Aroach
we will first distribute candies considering only left neighbours,(store it in an array)
then we will distribute candies considering only right neighbours,(store it in an array)
then the actual distribution for i would be max(left[i],right[i])
sum the actual distribution to get answer
*/

int BRUTE(vector<int> &ratings) // T.C O(N),S.C O(N)  optiaml:- T.C O(N),S.C O(1)
{

    int n = ratings.size();
    vector<int> left(n);  // stores candies distribution condsidering left neighbours
    vector<int> right(n); // stores candies distribution condsidering right neighbours

    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i - 1] < ratings[i])
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
        else
        {
            right[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(left[i], right[i]);
    }
    return ans;
}

/*Optimal Aproach:- (recomended to watch vid)
we use the concept of slope
*/

int optimal(vector<int> &ratings) // challange is to do without using extra space
{
    int n = ratings.size();
    int i=1;
    int sum=1;
    while(i<n)
    {
        if(ratings[i]==ratings[i-1])
        {
         sum+=1;
         i++;
         continue;
        }
        int peak=1;
        while(i<n&&ratings[i]>ratings[i-1])
        {
            peak++;
            sum+=peak;
            i++;
        }
        int downPeak=1;
        while(i<n&&ratings[i]<ratings[i-1])
        {
            sum+=downPeak;
            downPeak++;
            i++;
        }
        if(downPeak>peak)
        {
            sum=sum+(downPeak-peak);
        }
    }
    return sum;
}
