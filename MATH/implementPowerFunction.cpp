#include <bits/stdc++.h>
using namespace std;

/*T.C O(log N)
we initialize ans=1
we check if our power( n ) is odd or even if it is odd, we do n-- and multiply x to our ans
if it is even we do n=n/2 and x=x*x we can do this because pow( 3,4 )=pow( 3*3,2)=pow(9,2)
we do this till n!=0
*/

double myPow(double x, long long n)
{

    bool xsign = true;
    bool nsign = true;
    if (x < 0 && n % 2 != 0)
    {
        xsign = false;
    }
    if (n < 0)
    {
        nsign = false;
    }
    x = abs(x);
    n = abs(n);
    double ans = 1;
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            n--;
            ans = ans * x;
        }
        n = n / 2;
        x = x * x;
    }

    if (!xsign)
    {
        ans = -ans;
    }
    if (!nsign)
    {
        ans = 1.0 / ans;
    }
    return (double)ans;
}
