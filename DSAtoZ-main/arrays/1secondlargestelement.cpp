/*
brute force approach:- sort the array and iterate from n-2 to 0
with condition if(arr[i]!=max){ smax==arr[i]; }
time complexity:- O(NlogN+N) if quick sort is done

better solution:- find the max and find smax with another loop with
condition if(arr[i]!=max){ if(smax<arr[i]){ smax==arr[i] } }
time complexity O(N+N)

OPTIMAL SOLULU:- TIME COMPLEXITY O(N);
it solves the prob in one loop
we keep udating max and smax 
see the code below


*/
#include<iostream>
using namespace std;

int secondlargest( int arr[],int n )
{
int max=arr[0];
int smax=-1;// if negative num, smax= i=INT_MIN
for( int i=1;i<n;i++ )
{
    if(arr[i]>max)
    {            
        smax=max;
        max=arr[i];
    }
    if( max>arr[i]&& arr[i]>smax  )
    {
        smax=arr[i];
    }

}
return smax;

}



#include<iostream>
using namespace std;
int main()
{
    int a[]={};
    cout<<secondlargest(a,20);
}
