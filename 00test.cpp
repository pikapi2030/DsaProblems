#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int>& v) 
{
int n=v.size();    
long long maxSoFar=v[0];
long long maxDiff=0;
long long maxTriplet=0;

for(int i=0;i<n-1;i++)
{
 maxSoFar=max((long long)v[i],maxSoFar);
 maxDiff=max(maxDiff,maxSoFar-(long long)v[i]);
 maxTriplet=max(maxTriplet, maxDiff*(long long)v[i+1]);
}

return maxTriplet;


}
