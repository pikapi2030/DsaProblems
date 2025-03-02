/*
find mising num in an array from 1 to n
arr=[1,2,5,9]
output= 3,4,6,7,8
*/
#include <iostream>
#include <vector>
using namespace std;
void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
}

/*
brute time comlexity O(N*N)
s.c O(1) res vector is not considered

*/

int present(vector<int> v, int i) // a function to chech if a num is present in array or not
{
    int n = v.size();
    for (int j = 0; j < n; j++)
    {
        if (v[j] == i)
        {
            return 1;
        }
    }
    return 0;
}

vector<int> misbrute(vector<int> v)
{
    vector<int> res;
    int n = v.size();
    for (int i = 1; i < v[n - 1]; i++)
    {
        if (!present(v, i))
        {
            res.push_back(i);
        }
    }
    return res;
}
/*
better solution
use hashing,num with 0 as a hash is mising
T.c O(n+last element value)
s.c O(last element value) not considering space to return

*/
vector<int> misbeter(vector<int> v)
{
    vector<int> res;
    int n = v.size();
    vector<int> hash(v[n - 1] + 1, 0); // a hash vector of size of last element +1 of v with every index 0
    for (int i = 0; i < n; i++)
    {
        hash[v[i]]++;
    }
    for (int i = 1; i < hash.size(); i++)
    {
        if (hash[i] == 0)
        {
            res.push_back(i);
        }
    }
    return res;
}

/*
better SOL 2
conditions - only 1 missing num
we have been given a array till 1 to N with N-1 elements(so only one is missing)
we will calc sum of the array and sum of first n natural numbers(n*(n+1)/2)
and subtract them, the difference would be the missing number 
T.C O(size of v)
S.C O(1)
*/


int misbetter2(vector<int>v,int N)
{
    int sum=0;
    for(auto it=v.begin();it!=v.end();it++)
    {
    sum=sum + *(it);
    }
    return -sum+(N*(N+1)/2);
}
/*
conditions - only 1 missing num
we have been given a array till 1 to N with N-1 elements(so only one is missing)

the most optimal solution is the XOR aproach
it is slightly better as when dealing with large numbers our sum can exceed int limits
but our XOR will not exceed the bigger number

XOR is biniary operation like AND and OR  with symbol ^
XOR of two same numbers is 0  (n^n=0)
XOR of 0 and n is n   (n^0=n)

now we calculate the xor of all number in the given array 
like xor1=1^2^3^4...
then we will calculate XOR if numbers  1  to  N like xor2= 1^2^3^4...^N

now if we think  (xor1)^(xor2) 
let x be the missing num
it would be like  (1^1)^(2^2)^(3^3)^x^(4^4)^(N^N) 
only x will not be able to find its pair (as it is missing) 
so all other will become zero(n^n=0)  and it would be 
like 0^0^0^x^0^0... which would result in 0^x  as (0^0=0)
and 0^x=x
SO XOR1^XOR2 gives us the missing number

to calculate XOR1 (xor1=0 initialy)

we run loop from 0 to n 
xor=xor^v[i]
we can use another loop for xor2 
now the challange is to calculate xor1 and xor2 in one single loop (for O(n))

xor2=xor2^(i+1) 
xor2 is xor of the complete array(the one with no missing num)
so when going from 0 to n in array with missing num
we can do i+i to mimik going from 1 to N-1
then we can xor2=xor2^N  this would be our xor2
*/
int misopti(vector<int>v)
{
    int xor1=0,xor2=0;
int n=v.size();
for(int i=0;i<n;i++)
{
xor1=xor1^v[i];
xor2=xor2^(i);//xor of array 1 to N but N is not yet xored(N is the last num of i to N array)
}
xor2=xor2^(n);
return xor1^xor2;

}

int main()
{
    vector<int> v = {0,1};
    cout<<misopti(v);
}