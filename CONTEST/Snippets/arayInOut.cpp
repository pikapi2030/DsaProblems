#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;

while(t--)
{
 int n;
 cin>>n;
 int x;
 cin>>x;
 vector<int>v(n);
 for(int i=0;i<n;i++)
 {
    cin>>v[i];
 }
 //code
int sum=0;
for(int i=0;i<n;i++)
{
 sum=sum+v[i];   
}

cout<<ceil(sum/x)<<endl;



}
}