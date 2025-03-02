/*
sort and array consiting of 0 1 and 2 only
*/
#include<bits/stdc++.h>
using namespace std;
/*
brute force solution
using any sorting algorithm
*/

/*
better solution
counter number of zeroes ones and twos 
then modify the array
T.C O(2N)
S.C
*/
void sobetter(vector<int>&v)
{
    int n=v.size();
    int c1=0,c2=0,c0=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0){c0++;}
        else if(v[i]==1){c1++;}
        else{c2++;}
    }
    //CAN USE FOR LOOPS INSTEAD OF WHILE TO REDUCE DECREMENTING COUNTERS
    int i=0;
    while( c0>0 )
    {
      v[i]=0;
      i++;
      c0--;
    }
    while(c1>0)
    {
        v[i]=1;
        i++;
        c1--;
    }
    while(c2>0)
    {
        v[i]=2;
        i++;
        c2--;
    }
}

/*
OPTIMAL SOLUTION 
DUTCH NATIONAL FLAG ALGORITHM
T.C O(N)
S.C(1)
see in algorithms folder
*/
void DNF(vector<int> v)
{
    int n = v.size();

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            mid++;
            low++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else // v[mid]==2
        {
            swap(v[high], v[mid]);
            high--;
        }
    }
}
