#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int>v={1,2,4,5};
  int xors=0;
  for(auto it:v)
  {
    xors=xors^it;
  }
  cout<<xors;
}