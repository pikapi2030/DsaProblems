/*
q
rotate the array from left by k
if a={1,2,3,4} and k=2
then a={ 3,4,1,2 }
if k=1
a={2,3,4,1}
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
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

void rotator( int arr[],int k,int n )
{  
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
    int a[]={ 1,2,3,4,5 };
    rotator(a,3,5);
    printarray(a,5);

}
*/

/*
OPTIMAL SOLUTION:-
revrse the array from 0 to k-1; then from k to n-1
then reverse the whole array
*/
void printv(vector <int>a)
{
    for( auto it=a.begin();it!=a.end();it++  )
{
    cout<<*(it)<<" ";
    
}
cout<<endl;

}


void leftopti( vector<int>&v,int k )
{
int n=v.size();
reverse(v.begin(),v.begin()+k);
reverse(v.begin()+k+1,v.end());
reverse(v.begin(),v.end());

}
int main()
{
    vector<int>v={1,2,3,4,5};
    leftopti(v,3);
    printv(v);
}
