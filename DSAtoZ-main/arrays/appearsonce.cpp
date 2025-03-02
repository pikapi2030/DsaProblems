/*
find the only num which appears once in an array where all others appear twice
v={2,2,1,4,5,6,6,5,4}
ans =1

//IF THE ARRAY IS SORTED THEN WE CAN USE BS FOR O(log N) T.C
*/
using namespace std;
#include <bits/stdc++.h>

/*
brute:-
using two for loops
find frequency if equal to one then return
T.C  O(n*n)
S.C O(1)

*/
int apbrute(vector<int> v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (v[i] == v[j])
      {
        cnt++;
      }
    }
    if (cnt == 1)
    {
      return v[i];
    }
  }
}

/*
better approach
map hashing (can't use hashing if array has too large or negative nums)
T.C   O(NlogM)+O(N/2+1)   O(N/2+1) is t.c fetch loop
since M= N/2+1 
N/2+1 because most elements appear twice and only one element appears once
S.C O(N/2+1) space of map
*/

int apbetter(vector<int> v)
{
  int n = v.size();
  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[v[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (mp[v[i]] == 1)
    {
      return v[i];
    }
  }
}

/*
OPTIMAL APROACH
XOR APROACH do xor of all , since n^n=0 and 0^n=n
only number which appears once will we the final xor
T.C O(N)
S.C O(1)
*/
int apopti( vector<int>v )
{
  int xo=0;
for(int i=0;i<v.size();i++)
{
xo=xo^v[i];
}
return xo;
}

int main()
{
  vector<int> v = {1};
  cout << apopti(v); 
}
