#include<bits/stdc++.h>
using namespace std;
void printv(vector <int>a)
{
    for( auto it=a.begin();it!=a.end();it++  )
{
    cout<<*(it)<<" ";
    
}
cout<<endl;

}

/*
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements,
 you must return an array of alternately positive and negative values.
 Note: Start the array with positive elements.
 arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5
*/

/*
BRUTE
we maintain two arrays one which stores positive elements and one which stores negative 
elements
then we iterate from 0 to n/2 modifying our array
T.C O(n+n/2)
S.C O(n)
*/

vector<int> arrangebrute(vector<int>v)

{
int n=v.size();
vector<int>p;
vector<int>ne;

for(int i=0;i<n;i++)
{
   if(v[i]>0)
   {
    p.push_back(v[i]);
   }
   else
   {
    ne.push_back(v[i]);
   }
}
for(int i=0;i<n/2;i++)
{
    v[2*i]=p[i];
    v[2*i+1]=ne[i];
}
return v;
}

/*
OPTIMAL APPROACH
T.C O(N)
O.C O(N)
we maintain an ans array and pass through orignal
if v[i]>0 put v[i] in even index if v[i]<0 put v[i] in odd indexes

*/
vector<int> arrangeopti(vector<int>v)
{
    int ni=1;
    int pi=0;
    int n=v.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
        {
        ans[pi]=v[i];
        pi+=2;
        }
        else
        {
            ans[ni]=v[i];
            ni+=2;
        }
    }
    return ans;
}

/*
VARIETY TWO
the number of negative and positves are not equal
if any negative or positives left arrange them adjacently at the end of array

optimal approach is same as brute force aproach of variety 1
with little additions 
*/

vector<int> variety2opti(vector<int>v)
{
    int n=v.size();
vector<int>p;
vector<int>ne;

for(int i=0;i<n;i++)
{
   if(v[i]>0)
   {
    p.push_back(v[i]);
   }
   else
   {
    ne.push_back(v[i]);
   }
   
}
if(p.size()>ne.size())
{
    for(int i=0;i<ne.size();i++)
    {
        v[i*2]=p[i];
        v[2*i+1]=ne[i];
    }
 
}
return v;

}
int main()
{
    vector<int>v={-1,1,2,-3,4,5,6};
    printv(variety2opti(v));
}