#include <bits/stdc++.h>
using namespace std;
// Given an integer n, return the number of prime numbers that are strictly less than n.

// use seive of erastothenes
int countPrimes(int n)
{
    int ans = 0;
    vector<bool> isPrime(n, 1);
    for (int i = 2; i * i <n; i++)
    {
        if (isPrime[i] == 1)
        {
            
            for (int j = i * i; j <n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for(auto it:isPrime)
    {
        cout<<" "<<it<<" ";
    }
    cout<<endl;

    return ans;
}

int main()

{
    cout<<countPrimes(10);
}
