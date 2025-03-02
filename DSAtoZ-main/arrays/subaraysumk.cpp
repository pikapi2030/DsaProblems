#include<bits/stdc++.h>
using namespace std;

/*
count total number of subarrays with sum equal to k
*/

/*
brute 
using 3 for loop 
T.C O(n^3)
O.C O(1)
*/


int subbetter(vector<int>v,int k)
{
    int cnt=0;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum=sum+v[j];
            if(sum==k)
            {
                cnt++;
            }
        }
    }
}

/*
better
using  forloops
T.C O(n^2)
s.c O(1)
*/

/*
optimal
T.C O(N*LOGN)
S.C O(N)
*/

int subopti(vector<int>v,int k)
{
  int n=v.size();
map<int,int>mp;
int prefixsum=0;
int cnt=0;
mp[0]=1;
for(int i=0;i<n;i++)
{
    prefixsum=prefixsum+v[i];
    int rm=prefixsum-k;
    cnt=cnt+mp[rm];
    mp[prefixsum]=mp[prefixsum]+1;

}
return cnt;
}