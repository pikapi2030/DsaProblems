#include<bits/stdc++.h>
using namespace std;
/*
given a array with positives and negatives
return max of (sums of all sub arrays)
*/

/*
brute solution
using three for loops(nested)
two for the creating every sub array and one for finding sum
T.C O(n^3)
S.C O(1)
*/
int maxsumbrute(vector<int>v)
{
    int n=v.size();
    int maxs=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int l=i;l<=j;l++)
            { 
             sum=sum+v[l];
            }
            maxs=max(maxs,sum);
        }
    }
    return maxs;
}

/*
better solution
using two for loops
doing sum in second array itself
*/

int maxsumbetter(vector<int>v)
{
    int n=v.size();
    int maxs=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum=sum+v[j];
             maxs=max(maxs,sum);

        }

    }
    return maxs;
}

/*
optimal solution 
use kadane's algorithm
T.C O(N)
S.C O(1)
*/
int KAD( vector<int>v)
{

int sum=0,maxs=INT_MIN;
for(int i=0;i<v.size();i++)
{
sum=sum+v[i];
maxs=max(sum,maxs);
if(sum<0)
{
    sum=0;
}
}
return maxs;
}
