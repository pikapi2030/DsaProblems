#include<bits/stdc++.h>
using namespace std;
/*
we have been given two sorted arrays, one is V1 and other is V2
we have to find pairs between V1 and V2 {V1[i],V2[j]} such that V1[i]>V2[j]
i and j are iterators of V1 and V2

example v1={2,3,5,6}  v2={2,2,4,4,8};
possible pairs=  {3,2},{3,2},{5,2},{5,2}{5,4},{5,4},{6,2},{6,2},{6,4},{6,4}
output=10

*/

/*BRUTE
maintain a cnt
using two nested for loops, i iterates through V1 and nested j through V2
if V1[i]>V2[j] cnt++

T.C O(n^2)
S.C O(1)
*/

int BRUTE(vector<int>v1,vector<int>v2)
{
    int cnt=0;
    int n=v1.size();
    int m=v2.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v1[i]>v2[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

/*OPTIMAL
WE know the arrays are sorted so if at any point
V1[i]>V2[j]  then all elements from i to n-1 can make pairs with V2[j]  since going further
int V1[i] will increse it's value(ascending)  so pair is guranteed
so instead of adding one to our cnt we will add elements left from i to n-1
and from from that i and then increment j

and if V1[i]<V1[j] then tha V1[i] will not be be able to make pair with any
of the j present ahead so we will do a i++

T.C O(n+m)(total size of both arrays)
S.C O(1)
*/

int optimal(vector<int>v1,vector<int>v2)
{
    int cnt=0;
    int n=v1.size();
    int m=v2.size();
    int i=0,j=0;
    while(i<n)
    {
        if(v1[i]>v2[j])
        {
            cnt=cnt+(n-i);
            j++;
        }
        else if(v1[i]<=v2[j])
        {
            i++;
        }
    }
return cnt;
    
}

int main()
{
    vector<int>v1={2,3,5,6};
    vector<int>v2={2,2,4,4,8};
    cout<<optimal(v1,v2);
}
