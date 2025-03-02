#include <bits/stdc++.h>
using namespace std;
/*
We are given a row-wise sorted matrix of size r*c,
we need to find the median of the matrix given.
It is assumed that r*c is always odd.
Input:
1 3 5
2 6 9
3 6 9
Output:
Median is 5
If we put all the values in a sorted array A[] = 1 2 3 3 5 6 6 9 9)

Input:
1 3 4
2 5 6
7 8 9
Output:
Median is 5
*/

/*BRUTE
store all values of matrix in a 1D array,sort it and return the value at centre of it

T.C O((n*m)+(n*m)log(n*m))
*/

/*optimal
it is given that total number of elements are odd, so median will always be present in our
matrix

for a element to be median, it must be greter than or equal to  (n*m)/2 elements

so we will use BS, low as smallest element, high as largest element(search space)
than for mid, we will calculate from how many nubers our mid is greater
if it is less than required, we will eliminate left half, if it equal or more than required
we eliminate right half
at the end of the loop our low will be pointing to the ans(polarity swap)

all that left is to write a function which calculates how many numbers our mid is
greater than


*/

/*FUNCTION
we will write a function which calculates how
 numbers our mid is greater thanor equal to is
 we can do this using BS, we will perform BS in every row, and calculate upperbound
 we will add upperbound of all rows to get our ans, this would be the count of
 numbers smaller than or equal to our mid
*/

int Counter(vector<vector<int>> &v, int mid)
{
    int cnt = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cnt += (upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin()); /*upper bound gives the
                lowest index, whcih has greater element than target, therefore that index
                is equal to how many elements are smaller than target in that row*/
    }
    return cnt;
}

int OPTIMAL(vector<vector<int>>&v)
{
    int n=v.size(),m=v[0].size();
    int req=(n*m)/2;//req count for median
    
    int low=INT_MAX;/* calulatinf lowsest value in matrix */
    int high=INT_MIN;
    /*we only checking in first and last column, 
since rows are sorted. min from first column will be lowest 
max from last column will be highest*/

    for(int i=0;i<n;i++)
    {
        low=min(low,v[i][0]);
        high=max(high,v[i][m-1]);
    }
while(high>=low)
{
    int mid=(low+high)/2;
    if(req>=Counter(v,mid))//need a larger mid value
    {
     low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
return low;


}
