#include <bits/stdc++.h>
using namespace std;

/*
given two sorted arrays of size n and m, merge then and find median of the resultant array
expected T.C O(log(m+n))
*/

/*BRUTE
merge the two arrays using extra space and two pointer aproach
calculate median
T.C O(n+m)
S.C O(n+m)
*/

double BRUTE(vector<int> v1, vector<int> v2)
{
    int m = v1.size();
    int n = v2.size();
    int i = 0, j = 0;
    vector<int> res;
    while (m > i && n > j)
    {
        if (v1[i] >= v2[j])
        {
            res.push_back(v2[j]);
            j++;
        }
        else
        {
            res.push_back(v1[i]);
            i++;
        }
    }
    while (m > i)
    {
        res.push_back(v1[i]);
        i++;
    }
    while (n > j)
    {
        res.push_back(v2[j]);
        j++;
    }
    if ((m + n) % 2 != 0) // if total is odd
    {
        return res[(m + n) / 2];
    }
    else
    {
        return ((double)res[(m + n) / 2] + (double)res[(m + n - 1) / 2]) / 2;
    }
}

/*BETTER
we try to eliminate the extra space used
instead of storing the whole array, we wiil try to get just two elements needed for
our ans  (median involves 2 elemnts out of the whole array,one if n+m==odd)

first we will calculate the keep two var index1 and index2 which contain the index
of the two elements on the resultant array(not actually creating any res arrayn just hypothetical)

let n1=n+m
index2=(n+m)/2 index1=index2-1
we also keep two another var el1 and el2, which stores values at these indexes(we do not know)
we will keep a cnt var which stores index of the resultant array(keeps track of on which index
we are cuurently in our hypothetical res array)

T.C O(n+m)
S.C O(1)
*/

double BETTER(vector<int> a, vector<int> b)
{

    int m = a.size();
    int n = b.size();

    int index2 = (n + m) / 2, index1 = index2 - 1;
    int el1, el2;
    int cnt = 0;
    int i = 0, j = 0;
    int found = 0; // counts if both el1 and el2 are found or not if found break the loop
    while (m > i && n > j)
    {
        if (found == 2)
        {
            break;
        }
        if (a[i] > b[j])
        {
            if (cnt == index1)
            {
                el1 = b[j];
            }
            if (cnt == index2)
            {
                el2 = b[j];
            }
            cnt++;
            j++;
        }
        else // b[j]>a[i]
        {
            if (cnt == index1)
            {
                el1 = a[i];
            }
            if (cnt == index2)
            {
                el2 = a[i];
            }
            cnt++;
            i++;
        }
    }

    while (m > i)
    {
        if (found == 2)
        {
            break;
        }

        if (cnt == index1)
        {
            el1 = a[i];
        }
        if (cnt == index2)
        {
            el2 = a[i];
        }
        cnt++;
        i++;
    }

    while (n > j)
    {
        if (found == 2)
        {
            break;
        }

        if (cnt == index1)
        {
            el1 = b[j];
        }
        if (cnt == index2)
        {
            el2 = b[j];
        }
        cnt++;
        j++;
    }
    if ((n + m) % 2 != 0)
    {
        return el2;
    }
    else
    {
        return ((double)el1 + (double)el2) / 2;
    }
}

/*OPTIMAL
if n+m=even
in optimal aproach we will use binary search
what we will do is try to form correct symmetry

correct symmetry means on left all number which should be on left(in merged array)
are present, on right all element belonging to right are present

let's say we have an v1 of size 3 and v2 of size 5
so we need (5+3)/2=4 elements on both sides,
now to form a symmetry we pick let's say k element from v1, so we put
k elements from v1 in top left half,  4-k elements from v2 in bottom left half
3-k (3 is size of v1) elements from v1 in top right half, 5-(4-k)=1+k(5 is size of v2)
elements from v2 in bottom
right half

no we formed a symmetry, but we want to check if it is valid or not
we simply compare top left(TOPl) with bottom right(BOTr), and bottom left(BOTl) with top right
(TOPr)
we do not need to compare topl with topr since they are from same arrays (v1)
and v1 is already sorted, same reason not to compare botl, botr

for a valid symmetry topl and botl should be smaller than botr and botl
(a valid symmetry means all element on left are smaller than all on right)

once we have verrified the symmetry, if it is valid
median= (max(botl,topl)+min(topr+botr))/2

applying BS in this aproach

we will search for k such that symmetry is appropriate
k is the number of elements picked from v1 to topl, other values can be calculated by k
now the limits of search space is from 1 to size of v1(v1 represents the array from which we are picking)
since we have to atleast pick 1 element from v1 to make a valid righ and left half
(
example v2={1,2,3}
v1={1,7,9,10,15}

now if k=0;       no elements | 1,7,9,10,15
                  1,2,3       | no elmets
                  we can see left has only 3 and right has 5 elements
                  but we need equal elements on both sides so
                  we start k from 1
lets take same example but v1 is smaller than v2
v1={ 1,2,3 }
v2={1,7,9,10,15}
                 if k=0
                 no elements|1,2,3
                   1,7,9,10 |15

                   THIS IS A VALID SYMMETRY, (both sides have 4 elements)

                   NOTE:::no element ON LEFT=INT_MIN 
                   (we want left to be smaller and during comparison we want no errors)


                  NOTE: IF WE ARE DOING BS IN LARGER ARRAY, THAN K STARTS FROM 1
                  IF WE DOING BS IN SMALLER ARRAY , K=0 IS VALID
)
FOR BETTER T.C AND SMALLER SEARCH SPACE WE DO BS ON ARRAY WITH LESS ELEMENTS 
as search space is from 1 to size of array

CONDITIONS OF ELIMINATION:-
dont forget top elements are of V1, bottom are of V2
IF topl>botr  then it means we picked too much from v1(the more we pick, the more larger numbers we get in topl)
so we will decrease k (eliminate right half)
if botl>topr then it means we picked too less from v1(we need bigger numbers in V1)
so we increase k(eliminate left half)

NOTE: mid1=low+high/2(MID 1 means how many elements we picking from V1 basically k)
    if mid1=k then 
    mid2=(total needed on left half)-k= (v1.size()+v2.size()/2)-k
    
NOTE: mid1 and mid2 WILL ALWAYS point to topr and botr(observation)
 topl=v1[mid1-1]  topr=v1[mid1]
 botl=v2[mid2-1]  botr=v2[mid2]
NOTE:  if we pick all elements from v1, so k=mid1=v1.size(); THEN MID1 IS NOT A VALID INDEX
SO BEFORE ASSINING TOPL,TOPR,BOTL,BOTR, CHECK IF THE INDEX IS VALID OR NOT
IF NOT VALID ASSUME DEFUALT INT_MIN VALUE for lefts, INT_MAX for rights
 MEDIAN=(max(topl,botl)+min(topr,botr))/2.0

 FOR n+m=odd
 we will simply take one extra element in left side to form symmetry
 so elements needed on left side= (n+m+1)/2
 NOTE: elements needed for left side =(n+m+1)/2 ALSO WORKS FOR EVEN N+M
 if n+m=7,  then it gives 4 elements on left
 if n+m=8 , then it gives 4 on left(int datatypes ingnore decimals)
 

T.C O(min(n,m))
S.C O(1)
*/

double OPTIMAL(vector<int>v1,vector<int>v2)//doing BS on first argument
{
    int n=v1.size();
    int m=v2.size();
    if(n>m)//if V2 smaller DO BS on V2
    {
        return OPTIMAL(v2,v1);//(SWAPPED THE ARGUMENTS AS WE DO BS ON FIRST ARGUMENT)
    }
  long long low=0;
  long long high=v1.size();
  while(high>=low)
  {
    long long mid1=(low+high)/2;//picking mid1 elements from v1
    long long elements_required_in_left_to_form_symmetry=(n+m+1)/2;
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
        if((n+m)%2==0)//EVEN CASE
        {
         return ((double)max(l1,l2)+(double)min(r1,r2))/2.00;
        }
        else//ODD CASE
        {
        return max(l1,l2);
        }
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
