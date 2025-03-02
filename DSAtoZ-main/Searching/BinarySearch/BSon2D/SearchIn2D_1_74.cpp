#include <bits/stdc++.h>
using namespace std;
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.


*/

/*BRUTE
using two nested loop and traverse the whole matrix, if element found return true
not writing code for it
*/

/*BETTER
we see if there is a poosiblity of our target in Ith row
(if our tarhet lies between first and last element of that row, there is possibility)
if there is possibility, then we apply BS
considering each row as an array and applying BS to searh the element
if found return true

we have to do BS only one time(if our target is not present in the row where there is
possibility, it won't be present in other rows as well)

T.C O(n)+log_2 m  (we are performing BS only one time)
*/

bool BinarySearch(vector<int> v, int target)
{
    long long low = 0, high = v.size() - 1;
    while (high >= low)
    {
        long long mid = (high + low) / 2;
        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

bool BETTER(vector<vector<int>> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (target >= v[i][0] && target <= v[i][v[0].size() - 1]) // there is possibility of target in this row
        {
            return BinarySearch(v[i], target);
        }
    }
    return false; // dummy return actually
}

/*OPTIMAL
WE KNOW THAT WHOLE MATRIX IS SORTED

lets imagine we convert this all 2D array into one single array (1D)

if we do that, we can apply BS on that single array and find our target
in T.C of O(log_2  n*m)  (n*m would be the size of that single 1D array)

but we can't really use extra space, plus making a 1D array like that will already cost
us a T.C of O(n*m)

so we try to create 1D hypothetically withou any extra space

we know a matrix has cooedinates, a 1D array has indexes
we simply have to find a relation between these coordinates and indexes
(imagine a number k having coordinate a,b will have some index l in 1D )

the relation is
row coordinate=k/m  (where k is index value in 1D, m is number of columns)
column coordinate= k%m

THEREFORE    (a,b)=(k/m,k%m) is THE RELATION
to undestand the intiution of the relation watch vid(3 min part)

T.C O(log_2 n*m)
S.C O(1)
*/

bool OPTIMAL(vector<vector<int>> v, int target)
{
    int n = v.size();
    int m = v[0].size();
    long long low = 0, high = (n * m) - 1;//start and end of the hypo 1d array
    while(high>=low)
    {
    long long mid=(low+high)/2;
    //now mid is in index form, we convert this in coordinate form
    long long rowCoordinate=mid/m;
    long long columnCoordinate=mid%m;
    //now we can use conditions
    if(v[rowCoordinate][columnCoordinate]==target)
    {
        return true;
    }
    else if(v[rowCoordinate][columnCoordinate]>target)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
    }
    return false;   

}
