#include<bits/stdc++.h>
using namespace std;

/*
find nth root of m(an integer)
if in decimal,return -1

*/

/*BRUTE
we run loop from 0 to m, and use pow function
if pow(i,n)==m
return i;
if(pow(i,n)>m)
return -1;

T.C O(M*LOG_2 N)  m for loop and log_2 N for pow function
*/

int BRUTE(int n,int m)//m is the num jiska nth root chaiye
{

for(int i=0;i<m;i++)
{
if(pow(i,n)==m)
{
    return i;
}
else if (pow(i,n)>m)//value exceeded means ans in decima
{
    break;
}

}
return -1;
}

/*OPTI
we use BS
we search from 0 to m if pow(mid,n)>m then elimintae right half
if pow(mid,n)<m then eliminate left half
if equal then return mid

T.C O((log_2 M)*(log_2 N))  one log is for bs of search space m a,d other for pow function

*/

int optimal1(int n,int m)
{
long long  low=0,high=m;

while(high>=low)
{
    long long mid=(low+high)/2;

if(pow(mid,n)==m)
{
    return mid;
}
    if(pow(mid,n)>m)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
}
return -1;
}

/*DEALING WITH OVERFLOW
when numbers are too large our optimal 1 solution can throw an overflow error
because we are calulating mid^n, to avoid this we will calculate mid^n
iteratively and the moment it crosses m, we will stop calculating the value to prevent 
overflow

T.C O(nlogm)
*/
//writing an indicator function
/*
if  ans==m return 1
if ans>m return 0
if (ans<m) return 2
*/
int midIndicator(int mid,int n,int m)
{
    long long ans=1;//in end of the loop if will have mid^n value
    for(int i=1;i<=n;i++)
    {
        ans=ans*mid;
        if(ans>m)//if at any point our ans becomes greates than m we stop
        //this saves us from overflow we are not calculating the whole vaue of mid^n
        {
            return 0;
        }
        

    }
    if(ans==m)
    {
        return 1;
    }
    else
    {
        return 2;
    }

    
}

int opti2(int n,int m)
{
long long  low=0,high=m;

while(high>=low)
{
    long long mid=(low+high)/2;

if(midIndicator(mid,n,m)==1)
{
    return mid;
}
   else if(midIndicator(mid,n,m)==0)
    {
        high=mid-1;
    }
    else 
    {
        low=mid+1;
    }
}
return -1;
}



