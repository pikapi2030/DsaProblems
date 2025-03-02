#include <bits/stdc++.h>
using namespace std;
/*
given array, return a sub array with maximum product
*/

/*BRUTE AND BETTER
generate all sub arayys
T.C O(n^3)
S.C O(1)
not writing the code(check other subarrays quetions for similar codes)

BETTER
using two for loops(check other subarrays quetions for similar codes)
T.C O(n^2)
S.C O(1)
*/

/*OPTIMAL

we can observe that if there are even number of -ve than max product will be prodcut
of whole array

if there are odd number of -Ve than max prodcut will be max (product of prefix,product of suffix)
where prefix is produc of all elements befor that negative and suffix is product of all
elements after that negative(see the code to undestand better why this works)
so we will from start maintain a prefix and suffix update the max(max,max(prefix,suffix))
and return max

now if any zero comes in between and makes our product zero, we will simply make it 1.
our suffix,prefix approach will see 0 as breaker of the array and see numbers between
0 as smaller arrays to calculat max product of, so it will work fine

T.C O(n)
S.C O(1)
*/

/*ANOTHER OPTIMAL(NOT CODED)
there is another solution using modified kadane algo which is no very intuitive and
more like a rattafication code (watch solution if want to)
the below code is better to tell to interviewer
*/

long long OPTIMAL(vector<long long> v)
{
    long long n = v.size();

    int prefix = 1;
    int suffix = 1;
    int maxproduct=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)//to handle zeroes
        {
            prefix = 1;
        } 
        if (suffix == 0)
        {
            suffix = 1;
        }
        prefix=prefix*v[i];
        suffix=suffix*v[n-i-1];
        maxproduct=max(maxproduct,max(prefix,suffix));
    }
    return maxproduct;
}