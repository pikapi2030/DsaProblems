#include <bits/stdc++.h>
using namespace std;

int SecondLargest(vector<int>v)
{
   int x,y=INT_MIN;
   int n=v.size();
   for(int i=0;i<n;i++)
   {
      if(v[i]>x)
      {
         y=x;
         x=v[i];
      }
      else if(v[i]>y)
      {
         y=v[i];
      }

   }
   return y;
}



