#include<bits/stdc++.h>
using namespace std;

/*
given an array, give next permutation of it
a next permutation is a number just bigger than that array made by arranging the digits
if the array is already at it's last pemutation return it's first permutaion
*/

/*
the brute solution is using recursion we will learn it in recursion playlist
T.C O(n!*n)

*/

/*
better solution 
using stl  function
next_permutation(v.begin(),v.end());
*/

/*
optimal 
we use our two observations that 1. next permutation has very similar prefix just a slight 
change
we have to find next bigger number
we find a break point i
from i to n we we be changing the order to get next permutation
0 to i-1 will remain constant and is our constant prefix
now from i+1 to n we will find a number just bigger than i to swap
with i to get just greater number, then the other numbers(i+1 to n) wil we arranged in 
acsending order to get just bigger

the break point is when a[i]<a[i+1]

T.C O(3N)
O.C O(1) 
*/
void printv(vector <int>a)
{
    for( auto it=a.begin();it!=a.end();it++  )
{
    cout<<*(it)<<" ";
    
}
cout<<endl;

}



vector<int> nextpermopti(vector<int>&v)
{
    int index=-1;//breakpoint index
    int n=v.size();
    for( int i=n-2;i>=0;i--)
    {
        if(v[i]<v[i+1])
        {   index=i;//finding the breakpoint
            break;
        }
    }
    if(index==-1)//no breakpoint found
    {      
          reverse(v.begin(),v.end()); //handiling the edge case if v is last permutation
          return v;
    }
    for(int j=n-1;j>index;j--)
    {
        if(v[j]>v[index])
        {
          swap(v[j],v[index]);
          break;
        }
    }
        
    reverse(v.begin()+index+1,v.end());
    return v;


}
int main()
{
    vector<int>v={1,2,3,4};
    nextpermopti(v);
    printv(v);
}
