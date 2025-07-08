#include <bits/stdc++.h>
using namespace std;
/*
pritn all prime factors with duplicate
example for 50= 2*5*5
using sieve
*/

/*approach T.C O(Nlog(logN))+logN
we pre compute an array, storing smallest prime factor of i,
then we can easily calculate the prime factors of n with this while loop

while(n!=1)
{
cout<<spf[n];
n=n/spf[n];
}
*/

vector<int>genSpf( int n )
{
    vector<int>spf(n+1);
    for(int i=2;i<=n;i++)
    {
        spf[i]=i;//initialisation
    }
    for(int i=2;i*i<=n;i++)
    {
     for(int j=i*i;j<=n;j=j+i)
     {
        if( spf[j]==j )
        {
            spf[j]=i;
        }
     }
    }
    return spf;
}
vector<int> primeFactors(int n)
{
    vector<int>ans;
    vector<int>spf=genSpf(n);
    while(n!=1)
    {
    ans.push_back( spf[n] );
    n=n/spf[n];
    }
    return ans;
}

int main()
{
    for(int it:primeFactors(1e5))
    {
        cout<< " "<<it<<" ";
    }
}


