#include <bits/stdc++.h>
using namespace std;
/*
this algorithm is used to extract prime numbers till N in T.C of  O(n)+O(Nlog(logN))+O(N)
S.C O(N+1)
it marks number which are prime as 1 and numbers which are multiple of primes as 0
we take an array size of N+1
*/


vector<int>seiveOfEratosthenes(int N)
{
    vector<int> isPrime(N+1,1);
    int size= isPrime.size();
   for(int i=2;i*i<=N;i++)//till square root of N as our inner loop starts from i*i
   {
    if( isPrime[i]==1)
    {
        for(int j=i*i;j<=N;j=j+i)//no need to start from i*2 as i*2 is multiple of 2 so it was already marked, similary i*3 is multiple of 3 it was already marked, i*i is multiple of i which is not marked
        {
             isPrime[j]=0;//marking multiples of primes as 0
        }
    }
   }
   vector<int>ans;
   for(int i=2;i<size;i++)
   {
    if( isPrime[i]==1)
    {
        ans.push_back(i);
    }

   }
   return ans;
}

int main()
{
    int t=1;
    while(t--)
    {
    int N;
    cout<<"ENTER NUMBAH:";
    cin>>N;
    vector<int>ans=seiveOfEratosthenes(N);
    for(auto it:ans)
    {
        cout<<" "<<it<<" ";
    }
    }
}

