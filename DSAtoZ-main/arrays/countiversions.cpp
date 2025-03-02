#include<bits/stdc++.h>
using namespace std;
//also know as count inversions
/*
give an array, count number of pairs such that a[i]>a[j]&&j>i

Example 1:
Input Format
: N = 5, array[] = {1,2,3,4,5}
Result
: 0
Explanation
: we have a sorted array and the sorted array has 0 inversions
 as for i < j you will never find a pair such that A[j] < A[i].

  More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so 
  this is not an inversion.

Example 2:
Input Format
: N = 5, array[] = {5,4,3,2,1}
Result
: 10
Explanation
: we have a reverse sorted array and we will get the maximum 
inversions as for i < j we will always find a pair such that A[j] < A[i].

Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which
 will satisfy out conditions and for reverse sorted array we will 
 get maximum inversions and that is (n)*(n-1) / 2.
 For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

Example 3:
Input Format
: N = 5, array[] = {5,3,2,1,4}
Result
: 7
Explanation
: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1)
 and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition. 

*/

/*BRUTE
maintain a cnt
use two nested for loops
one from i to n
other from i+1 to n(to make sure j>i)
if(v[i]>v[j]) cnt++

T.C O(n^2)
S.C O(1)
*/

int BRUTE(vector<int>v)
{
    int cnt=0;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i]>v[j])
            {
             cnt++;
            }
        }
    }
    return cnt;
}

/*OPTIMAL
the solution involves the fact that we can find inversions between two arrays efficiently
(see inversions between arrays optimal solution )
we will perform mergesort as it breaks down into smaller sorted array and than apply
inversion b/w arrays to get count of inversions

T.C O(NlogN)(SAME AS MERGE SORT)
S.C O(N) (temp array)
if we do not want to alter our array then S.C= O(2N)(temp and copy array)
*/


int cnt=0;//global var(KEEPING GLOBAR VARS IN AN INTERVIEW IS HIGHLY DICOURAGED)
void merge(vector<int> &v,int low,int mid,int high)
{
    vector <int> temp;
   int left=low;
   int right=mid+1;
    while( left<=mid && right<=high )
    {  
      if(v[left]<=v[right])
      {
        temp.push_back(v[left]);
        left++;
      }
      else
      {
        cnt=cnt+mid-left+1;//the condition is left>right so inversion forms
        temp.push_back(v[right]);
        right++;
      }
    }
      while( left<=mid )
      {
        temp.push_back(v[left]);
        left++;
      }
      while(right<=high)
      {
        temp.push_back(v[right]);
        right++;
      }
    
    for(int i=low;i<=high;i++)
    {
        v[i]=temp[i-low];//this is the line where our sorted orignal array forms
    }
}
void mergesort( vector <int> &v,int low,int high )
{ 
    int mid=(high+low)/2;
    if(low>=high){ return; }
    mergesort( v,low,mid );
    mergesort(v,mid+1,high);
    merge(v,low,mid,high);
   

}
int inversionsOPTI(vector<int>v)
{
    mergesort(v,0,v.size()-1);
    return cnt;
}

//OPTI FUNCTION WITHOUT USE OF GLOBAL VARIABLE

int mergeee(vector<int> &v,int low,int mid,int high)
{
    int count=0;
    vector <int> temp;
   int left=low;
   int right=mid+1;
    while( left<=mid && right<=high )
    {  
      if(v[left]<=v[right])
      {
        temp.push_back(v[left]);
        left++;
      }
      else
      {
        count=count+mid-left+1;//the condition is left>right so inversion forms
        temp.push_back(v[right]);
        right++;
      }
    }
      while( left<=mid )
      {
        temp.push_back(v[left]);
        left++;
      }
      while(right<=high)
      {
        temp.push_back(v[right]);
        right++;
      }
    
    for(int i=low;i<=high;i++)
    {
        v[i]=temp[i-low];//this is the line where our sorted orignal array forms
    }
    return count;
}
int mergesortsss( vector <int> &v,int low,int high )
{ int count=0;
    int mid=(high+low)/2;
    if(low>=high){ return count ; }
   count=count+ mergesortsss( v,low,mid );
    count=count+mergesortsss(v,mid+1,high);
    count=count+mergeee(v,low,mid,high);
    return count;
   

}
int inversionsOPTIII(vector<int>v)
{
   return mergesortsss(v,0,v.size()-1);
    
}

