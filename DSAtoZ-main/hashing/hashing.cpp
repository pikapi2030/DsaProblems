#include<iostream>
using namespace std;
/*
hashing mean having a hash array which stores frequency of numbers
occuring in another array, frequency of x number in array
will be at xth index in hash array
hash[arr[i]]++;
*/
int main()
{ int n;
cout<<"ENTER SIZE:";
cin>>n;
int arr[n];
    for(int i=0;i<n;i++)
    { cout<<"ENTER ELMENT:"<<i<<":";
      cin>>arr[i];
    }
/*lets assume max element in array is 20 so we make 
an hash array size of 21
*/
//pre-storing
int hash[21]={0};
for(int i=0;i<n;i++)
{
    hash[arr[i]]++;
}
//fetching
int q;//q stands for number of queries
cout<<"ENTER NUM OF QUERIES:";
cin>>q;
while(q--)
{
    int num;//the num you need freq of
    cout<<"ENTER THE NUM:";
    cin>>num;
    cout<<hash[num]<<endl;;
}

}
