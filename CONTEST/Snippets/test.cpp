#include <bits/stdc++.h>
using namespace std;

bool comp( pair<int,int>p )
{
int a=p.first;
int b=p.second;
if(a>b){ return true; }
if(a==b)
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int k;
        cin>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n;i++)
        {
            v[i]=v[i]%k;
        }
        vector<int>ans;
        sort(v.begin(),v.end(),comp);

    }
}