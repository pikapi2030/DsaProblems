#include<iostream>
#include<map>
using namespace std;
/*
hashing by use of maps is better than array hashing as it solves the problem of maximum 
array size to be 10^6
in map hashing the size of maps is determined by number of elements and not the values
of element

the number of which we need freq acts as key and the value is the freq

ORDERED VS UNORDERED MAPS
N is size of map
in orderedmap, t.c OF FETCHING AND INSERTION(one iteration)  will be O(logN) in worst,
best and average case

IN unorderedmap,(T.C of inset and fetch of one iteration ) 
it will be O(1) in average and best case BUT O(N) in worst case
so it is better to use unorderedmap usually until worst case happens and we have to use
ordered map

WORST CASE HAPPENS DUE TO COLLISONS WHEN ALL HASHES COME ON SAME KEY
(DIVISION METHOD ), WATCH VID

*/
int main()
{
  int n;
cout<<"ENTER SIZE:";
cin>>n;
int arr[n];
    for(int i=0;i<n;i++)
    { cout<<"ENTER ELMENT:"<<i<<":";
      cin>>arr[i];
      //mp[arr[i]]++;
      //PRE-STORING can be done while taking input,no need of extra for loop
    }
 
 //since array is size of n, we make a map with size of n
 map<int,int>mp;
//pre storing(can be done in iput loop itself)
for(int i=0;i<n;i++)
{
    mp[arr[i]]++;
}
//fethcing 
cout<<"ENTER NUM OF QUERIES:";
int q;
cin>>q;
while(q--)
{
    int num;
    cout<<"ENTER NUM:";
    cin>>num;
    cout<<mp[num]<<endl;
}


}