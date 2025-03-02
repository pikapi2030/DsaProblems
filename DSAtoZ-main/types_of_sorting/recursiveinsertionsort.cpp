#include<iostream>
using namespace std;

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
//expander is actually low+1(initially only) it decides the range of mini arrays formed
void recurinsertionsort( int arr[],int n,int expander )
{
    int high=n-1;
    if(expander>high){ return; }
int i=expander;
while( i>0)
{  
    if(arr[i-1]>arr[i])
   { swap(arr,i,i-1);}
    i--;
}
recurinsertionsort(arr,n,expander+1);
}

int main()
{
int a[]={9,8,-1,11,2,7,6};
recurinsertionsort(a,7,1);
printarray(a,7);

}