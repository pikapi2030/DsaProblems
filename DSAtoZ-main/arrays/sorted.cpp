#include<iostream>
using namespace std;
int sorted( int arr[],int n )
{
  for( int i=0;i<n-1;i++ )
  {
    if(arr[i]<=arr[i+1])
    { 
     
    }
   else{ return 0; }
  }
  return 1;
}
int main()
{
    int a[]={1,2,3,4,5};
    cout<<sorted(a,5);

}