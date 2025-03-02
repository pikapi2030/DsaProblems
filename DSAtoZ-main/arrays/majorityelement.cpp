#include <bits/stdc++.h>
using namespace std;

/*
majority element is the element in which's frequency is greater than N/2 where N
is size of array
task return majority element

*/

/*
brute force solulu
using a nested loop, keeping a counter and a check
T.C O(n*n)
S.C O(1)
*/

int majorbrute(vector<int> v)
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
        if (cnt > n / 2)
        {
            return v[i];
        }
    }
    return -1;
}

/*
better solution
in this solution we use hash map to store frequency
and check
T.C Nlog(N) +O(N)
S.C O(N) if array contains all unique elements
*/
    int majorbetter(vector<int> & v)
    {
        int n = v.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[v[i]]++;
            if (mp[v[i]] > n / 2)
            {
                return v[i];
            }
        }

        return 0;//return nothing usefull
    }

/*
optimal solution 
use morre's voting algorithm
T.C O(n)
S.C O(1)

*/
int MVA(vector<int>v)
{
    int n=v.size();
    int cnt=0;
    int num=v[0];
    for(int i=0;i<n;i++)
    { 

     if(v[i]==num)
     {
        cnt++;
     }
     else{cnt--;};   
     if(cnt==0)
     {
        num=v[i+1];
     }
     
    }
    return num;
}

