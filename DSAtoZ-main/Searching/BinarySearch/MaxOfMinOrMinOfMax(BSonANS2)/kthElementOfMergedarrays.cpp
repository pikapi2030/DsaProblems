#include<bits/stdc++.h>
using namespace std;
/*
give to sorted arrays, find kth element of the merged array
*/

/*OPTIMAL
WE will use the median of two sorted array aproach(solve THAT FIRST) optimal
we use BS to create symmetry
our left side will have k elments and right side will have (n+m)-k elements
where n and m are size of v1 and v2
SINCE VALID SYM MEANS OUR MEGED ARRAY FROM SORTED (ALL LEFT SMALLER THAN ALL RIGHT)

SO THE MAX ELMENT FROM LEFT WILL BE OUR KTH ELEMENT

so k= max(l1,l2)  

NOTE: WE NEED TO MODIFY OUR LOW AND HIGH
why?

example:(it is assumed m>n)
lets assume n=3, m=11 and k=13
so low =0 high=n=>3
mid=1
so we pick one element from v1  
since we need k elements on left
so we need 13 elements, we have picked 1 from v1
so we need to pick 12 from v2 
BUT THE PROBLEM IS V2 ONLY HAS 11 ELEMENTS
SO WE NEED TO MODIFY OUR LOW
WE CAN'T START FROM 0, WE NEED TO SET A MIN AMOUNT OF ELEMENT NEEDED TO BE PICKED FROM
V1 SO THAT ABOVE SITUATION DOES NOT OCCUR

so if k>m than we need to pick some number  elements from v1 
max(0,k-n) is the min amount of elements needed to be picked from v1(this also checks if k>m)

we also need to modify our high

example:
(it is assumed m>n)
lets assume n=10,m=20,k=2
low=0,high=n=10
mid =5
we only need 2 elements on left side

BUT WE ARE PICKING 5 elements already, OUR MID can't exceed our k
if k<n (m>n already assumed)
then our high should not exceed k
so 
high= min(k,n) (already checks for if k<n)



*/

int OPTIMAL(vector<int>v1,vector<int>v2,int k)//doing BS on first argument
{
    int n=v1.size();
    int m=v2.size();
    if(n>m)//if V2 smaller DO BS on V2
    {
        return OPTIMAL(v2,v1,k);//(SWAPPED THE ARGUMENTS AS WE DO BS ON FIRST ARGUMENT)
    }
  long long low=max(0,k-m);
  long long high=min(n,k);
  while(high>=low)
  {
    long long mid1=(low+high)/2;//picking mid1 elements from v1
    long long elements_required_in_left_to_form_symmetry=k;
    long long mid2=elements_required_in_left_to_form_symmetry-mid1;//if 5 elements required to from sym,and we pick 3 from v1, we have to pick 5-3=2 from v2
    long long l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
    /* l1=topl r1=topr
       l2=botl r2=botr
       THESE ARE DEFULT VALUES IF MID1 and MID2 are not valid indexes
       (which  happens when ,mid1=v1,size()
        or when elements on left=0 (mid2 becomes negative)
        mid2 can also becomes v2.size()
        mid1 can also become negative
    */
    if(mid1<n)r1=v1[mid1];//checking for valid index
    if(mid2<m)r2=v2[mid2];
    if(mid1-1>=0)l1=v1[mid1-1];
    if(mid2-1>=0)l2=v2[mid2-1];

    if(l1<=r2&&l2<=r1)//VALID SYMMETRY
    {
        return max(l1,l2);
    }
    else if(l1>r2)//we are picking too much from v1(we need to reduce l1 value)
    {
     high=mid1-1;//reducing value of picking reduces l1(sorted array, the more we pick the larger number we get)
    }
    else//(l2>r2) this means we are picking too much from v2, so to reduce l2, we pick less from v2, and to pick less from v2, we pick more from v1, so increase value
    {
        low=mid1+1;
    }

  }
   return 0;//to avoid conditional return error
}


