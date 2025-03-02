#include <bits/stdc++.h>
using namespace std;
/*SET MISMATCH(645 on leetcode)

*/
/*
given an array of size N, there is exactly one missing and one repeating num in array
from 1 to N, return those numbers like {repeating,missing)

Input Format
:  array[] = {3,1,2,5,3}
Result
: {3,4)
Explanation
: A = 3 , B = 4
Since 3 is appearing twice and 4 is missing

Example 2:
Input Format
: array[] = {3,1,2,5,4,6,7,5}
Result
: {5,8)
Explanation
: A = 5 , B = 8
Since 5 is appearing twice and 8 is missing

*/

/*BRUTE
we use two for loops to count the number, if repeting cnt=2, if not cnt=0
T.C O(N^2)
S.C O(1)
*/
vector<int> BRUTE(vector<int> v)
{
    int repeating = -1, missing = -1;
    int n = v.size();
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            repeating = i;
        }
        else if (cnt == 0)
        {
            missing = i;
        }
        if (missing != -1 && repeating != -1) // means missing and repeatinf are found
        {
            return {repeating, missing};
        }
    }
}

/*BETTER
using hashing, we make hasharray of n+1 size
T.C O(2N)
S.C O(N)
*/

vector<int> BETTER(vector<int> v)
{
    int n = v.size();
    vector<int> hash(n + 1, 0); // n=maximum element possible
    int repeating = -1, missing = -1;

    for (int i = 0; i < n; i++)
    {
        hash[v[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
     if(hash[i]==2){repeating=i;}
     else if(hash[i]==0){missing=i;}
     if(missing!=-1&&repeating!=-1)
     {
        return {repeating,missing};
     }

    }
}

/*OPTIMAL SOLUTION 1

we use maths
we know sum of first n numbers is ((n)*(n+1))/2
and sum of first n^2 numbers is   ((n)(n+1)(2n+1))/6

let msing num=X and repeting =Y

diffrerence b/w vector v and (sum of 1 to n) wil be X-Y
diffrenece b/w vector v(with all elememts squared) and sum of(1^2 to n^2) will be (X^2)-(Y^2)

which is (X+Y)(x-Y) now we know X-Y, so we calculate X+Y
since we know X+Y and X-Y we simply solve these equations

*/

vector<int>OPTIMAL1(vector<int>v)
{
    long long n=v.size();
    long long sum_till_n=n*(n+1)/2;
    long long sum_of_sq=(n)*(n+1)*(2*n+1)/6;
    long long sum=0;
    long long sumsq=0;

    for(int i=0;i<n;i++)
    {
     sum+=(long long)v[i];
     sumsq+=(long long)v[i]*(long long)v[i];
    }
    long long X_Y=sum-sum_till_n;
    long long XX_YY=sumsq-sum_of_sq;
    long long X_plus_Y=(XX_YY)/X_Y;
    long long X=(X_plus_Y+X_Y)/2;
    long long Y=X_plus_Y-X;
    return {(int)Y,(int)X};
    


}

/*OPTIMAL 2
uses xor and bit manipulation
will learn during bir manipulation 
*/
