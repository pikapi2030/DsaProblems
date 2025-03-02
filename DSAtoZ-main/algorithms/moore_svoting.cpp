#include<bits/stdc++.h>
 using namespace std;

 /*
 moores's voting algorithm is used to find majority element in an array
 majority element- occurs more than N/2 times in an array of size N

 THIS ALGO RETURNS A NUMBER WHICH IS THE ONLY POSSIBLITY OF MAJORITY ELEMENT
 it means that if majority element would exists this would be the one


 this algorithm works only if it is given that majority element does exists
 if it is not given that majority element does not exist
 after finishing this algo just check if returned numbe ris majority or not
 by iterating and calculating frequency

 we maintain  a counter and a pointer starting from v[0],num=v[0]
 now we iterate and do cnt++ if v[i]==num and cnt-- otherwise
 the moment cnt==0 we change our num next element from the postion of i currently
 i is where when  cnt became zero , the next element is chosen num and we 
 repeat the process 

 */

int MVA(vector<int>v)
{
    int n=v.size();
    int cnt=0;
    int num=v[0];
    for(int i=0;i<n;i++)
    { 

     if(v[i]==num)
     {
        cnt++;
     }
     else{cnt--;};   
     if(cnt==0)
     {
        num=v[i+1];
     }
     
    }
    return num;
}
