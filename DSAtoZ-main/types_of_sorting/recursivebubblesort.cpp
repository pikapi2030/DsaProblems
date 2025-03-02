#include <iostream>
using namespace std;
/*
time complexity
O(N^2) for average and worst
O(N) for best case after implementing didswap

*/
void printarray( int arr[],int n )
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
}
void swap(int arr[],int i,int j)
{
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;

}


void recursivebubblesort(int arr[], int low,int high)
{ 
    if(low>high){ return; }
    int i=low;
  int j=high-1;
  int didswap=0;
  while(i<=j)
  { 
    if(arr[i]>arr[i+1])
    { 
        swap(arr,i,i+1); 
        didswap=1;
    }
    i++;
  }
if (didswap==0){ return; }
  recursivebubblesort( arr,low,high-1 );
    
   
}
int main()
{
int a[]={1,2,64,97,11,25,27,30};
recursivebubblesort(a,0,7);
printarray(a,8);
}

