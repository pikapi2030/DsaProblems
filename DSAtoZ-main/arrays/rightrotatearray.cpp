/*
q
rotate the array from right by k
if a={1,2,3,4} and k=2
then a={ 3,4,1,2 }
if k=1
a={2,3,4,1}
*/
#include<iostream>
using namespace std;
void printarray( int arr[],int n )
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
}
void arraycopy( int newu[],int old[],int n )
{
    for(int i=0;i<n;i++)
    {
        newu[i]=old[i];
    }
}

void rightrotator( int arr[],int kr,int n )
{  int k=n-kr;
    int temp[n];
    int j=0;

    for( int i=0;i<n-k;i++ )
    {
        temp[i]=arr[i+k];
    }
  for( int i=n-k;i<n;i++ )
  {
   temp[i]=arr[j];
   j++;
  }
  arraycopy( arr,temp,n );
}
int main()
{
    int a[]={ 1,2,3,4,5,6,7 };
    rightrotator(a,3,7);
    printarray(a,7);

}
