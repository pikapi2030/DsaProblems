#include<iostream>
using namespace std;
/*
selection short is method of finding the min value and swapping it
with 1st index then find 2nd min value swap it with second index 
do it till array is sorted

TIME COMPLEXITY-
O(N^2)  or O(N(N+1)/2)
*/
void printarray( int arr[],int n )
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
}

void selectionsort( int arr[],int n )
{
    for( int i=0;i<n-1;i++ )
    {  int mini=i;
       for(int j=i;j<n;j++)
       {   
        if(arr[mini]>arr[j])
        {
            mini=j;
        }

       }
       int t=arr[i];
       arr[i]=arr[mini];
       arr[mini]=t;

    }
}
int main()
{
int a[]={5,20,3,8,2,6,362,5};
selectionsort(a,7);
printarray(a,7);

}