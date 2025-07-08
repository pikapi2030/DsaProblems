#include <bits/stdc++.h>
using namespace std;
/*
given a number n, print all primes numbers from 1 to n
*/

/*optimal approach  T.C O(N)+ O(N log(logN))
we try to precompute a binary array which will tell us if the number is prime or not

we initialize a bool array with 1(size n+1)
we start from 2, if 2 is marked as 1 , we mark all multiples of 2 as 0,
same we do for 3, when we come to 4, it is already marked as 0 so we skip it

by this way we precompute an array with all primes marked as 1
this can be further optimised

we can start the inner loop from i*i instead of 2*i
as 2*i will allready be marked by 2, lets say i=11, so 2*11,3*11,4*11...10*11 all will be
already marked by 2,3,5,7

we can also end the outer loop at sqrt(n) as we are starting from i*i
assume n=64,when we are at 8, we mark 64,then 8*9>n so we stop
now we do not need to go to 9, as we will be starting from 81 whic is biggern then
n


*/

vector<int> unoptimisedSeiveOfErastothenes(int n)
{
    vector<int> ans;
    vector<bool> isPrime(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> optimisedSiveOfErastothenes(int n)
{
    vector<int> ans;
    vector<bool> isPrime(n + 1, 1);
    for (int i = 2; i*i <= n; i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
