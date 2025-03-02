#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm'
 columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index.
If there's no row with at least 1 zero, return -1.
*/

/*BRUTE
we simply use two nested for loop to add all elements of each row
(number of 1s int that row=sum of that row,as it only has 1s and 0s)
we also have max_count and index var(to store index of the row)
id count>max_count then max_count=count
index=i;
T.C O(n*m)
S.C O(1)
*/

int BRUTE(vector<vector<int>> v)
{
    int max_count = 0;
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int current_count = 0;

        for (int j = 0; j < v[0].size(); j++)
        {
            current_count += v[i][j];
        }
        if (current_count > max_count)
        {
            index = i;
            max_count = current_count;
        }
    }
    return index;
}

/*OPTIMAL
we cannot optimise the row traversal(outer loop)
but we can optimise the opearation of inner loop by BS

so we will pass each row as an array and use BS to calculate occurences
forget about 2d, let's say we are in 1D
if we want to calculate number of 1's we will simply calculate
first occurence of one(lowest index of 1)
number of 1s=size of that array-lowest index of 1
we will simply repeat this process in 2D

FIRST OCCURENCE OF A NUMBER IS LOWER BOUND OF THAT NUMBER

T.C O(n*LOG_2 m)
*/

int LB(vector<int> v, int target)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (high >= low)
    {
        int mid = (low + high) / 2;

        if (v[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int OPTIMAL(vector<vector<int>> v)
{
    int max_count = 0;
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int First_occurence = LB(v[i], 1); // we pass each row as a matrix, with target 1
        int current_count = v[0].size() - First_occurence;
        if (current_count > max_count)
        {
            max_count = current_count;
            index = i;
        }
    }
    return index;
}