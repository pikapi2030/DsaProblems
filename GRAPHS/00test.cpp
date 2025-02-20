#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
	vector<int>a;
	vector<int>b;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
	    cin>>b[i];
	}
	
	int aSum=0;
	int bSum=0;
	for(int i=0;i<n;i++)
	{
	    aSum=aSum+a[i];
	    bSum=bSum+b[i];
	}
	if(aSum%2!=0||bSum%2!=0)
	{
	    cout<<"YES";
	    return 0;
	}
	int ors=0;
	int an=0;
	for(int i=0;i<n;i++)
	{
	    ors=ors+(a[i]||b[i]);
	    an=an+(a[i]&&b[i]);
	}
	if(ors%2!=0||an%2!=0)
	{
	    cout<<"YES";
	    return 0;
	}
	cout<<"NO";
	return 0;
	
    }
	

}
