#include <bits/stdc++.h>
using namespace std;

/*
given two numbers, l and r
return l^(l+1)^(l+2)....^r  ( basically xor all numbers from l to r )
*/

/*aproach
first lets try to find a way to calculate xor from 1 to n
then xor from l to r= (xor from 1 to l-1)^ (xor from 1 to r)
*/

int xorFromOnetoN(int n) // pattern based, no intuition
{
    if (n % 4 == 0)
    {
        return n;
    }
    if (n % 4 == 1)
    {
        return 1;
    }
    if (n % 4 == 2)
    {
        return n + 1;
    }
    if (n % 4 == 3)
    {
        return 0;
    }
}
int findXOR(int L, int R)
{
    return xorFromOnetoN(L - 1) ^ xorFromOnetoN(R);
}
