#include<bits/stdc++.h>
using namespace std;
/*
given a 2d matrix (n*n order) roatate it by 90 degree
*/


/*
brute force
we create an ans array, store values in ans array at correct place 
we will find a relation between i of v and i of ans 
simliarly for j
upon observation  ans[j][n-i-1]=v[i][j]

T.C O(n^2)
S.C O(n^2)
*/
void bruterotate(vector<vector<int>>v)
{
    int n=v.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-i-1]=v[i][j];
        }
    }
    v=ans;

}

/*
optimal solution 
first take transpose and then reverse the rows
T.C 
O((n/2)*(n/2)
*/

void opti(vector<vector<int>>v)
{
    int n=v.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }
    /* 
    this works too
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(v[i][j],v[i][n-j-1]);
        }
    }
    */
   for(int i=0;i<n;i++)
   {
    reverse(v[i].begin(),v[i].end());
   }
}
