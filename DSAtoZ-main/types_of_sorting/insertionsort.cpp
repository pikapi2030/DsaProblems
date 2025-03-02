#include<iostream>
using namespace std;

/*
it compares current element to left element
if unsorted then swap, now go to that left element again and check for it's left
countuniue till you reach start of the array

 TIME COMPLEXITY-
 worst(array in desending) and average case-O(n(n+1)/2)of O(n^2)
 best case(array in ascending)  O(n)

*/

void swap(int arr[],int i,int j)
{
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;

}
void printarray( int arr[],int n )
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
}
void insertionsort(int arr[],int n)
{
    for( int i=1;i<=n-1;i++ )
    {  int j=i;
        while(j>0&& arr[j-1]>arr[j])
        {
            swap(arr,j-1,j);
            j--;

        }
    }
}

int main()
{
  int  a[]={10,5,22,-45,-2,0,56};
  insertionsort(a,7);
  printarray(a,7);
}
