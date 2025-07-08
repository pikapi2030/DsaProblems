#include <bits/stdc++.h>
using namespace std;
/*
given a number n, print its all prime factors
*/
/*approach 1
check if a num divides n, T.C O(N*root(N))  we can check if a number is prime in O(root(N))

to optimise this approach we can run the loop till root N
and add other divisor as well
T.C O(rootN *rootN)  (approx)
*/

/*approach 2
school method of prime factorisation(does not require a prime check)
we run a loop from 2 to N, if it can divide n, we divide it until it cannot,
and add tha number to our list

worst case :- if the number is prime itself

T.C O(N)

to fix this we run loop till root N
and if N!=1, we also add N( the modified N due to n=n/i )
T.C root(N)*logN
*/

vector<int> primeFactors(int n)
{
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n != 1)
    {
        ans.push_back(n);
    }

    return ans;
}

int main()
{
    vector<int> v = primeFactors(INT_MAX - 1);
    for (auto it : v)
    {
        cout << " " << it << " ";
    }
}
