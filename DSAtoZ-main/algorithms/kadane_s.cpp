#include<bits/stdc++.h>
using namespace std;
//T.C O(N)
//S.C O(1)
/*
this is used to return maximum of (sum of every sub array)
in an array with negatives and positive(if it contains only
 positives the whole array is the output)
*/

/*
we keep a maxs and sum
if maintain sum till i and store it like maxs=max(maxs,sum)
if sum till i us less than zero we set it to zero(we trying to find max sum 
so no point in carrying a negative sum)
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
