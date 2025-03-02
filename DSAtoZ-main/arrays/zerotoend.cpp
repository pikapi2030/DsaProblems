/*
in an array move all zeroes to end 
arr=[1,2,0,5,0,7]
output arr=[1,2,5,7,0,0]
*/
//deleter which does not alter size
#include<iostream>
#include<vector>
using namespace std;
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << " " << arr[i] << " ";
    }
}
void swap(vector<int>&arr,int i,int j)
{
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;

}
void printv(vector <int>a)
{
    for( auto it=a.begin();it!=a.end();it++  )
{
    cout<<*(it)<<" ";
    
}
cout<<endl;

}




/*
brute force 
store all non zeroes in temp then put them in front of array
the put zeroes at end
time complexity:-
O(2N)
space complexity O(X) where x is num of non zeroes in array worst case O(N)

void zerosend(int arr[],int n)
{ 
    int cnt=0;
    int temp[n];
    for(int i=0;i<n;i++)
    {  
        if(arr[i]!=0)
        {
            temp[cnt]=arr[i];
            cnt++;
        }

    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    for( int i=cnt;i<n;i++ )
    {
        arr[i]=0;
    }
    
}
int main()
{
int a[]={1,2,0,5,0,3,0,0,1,0};

zerosend(a,10);
printarray(a,10); 
}
*/

/*
optimal solulu
keep two pointer i and j  j always remains on zeroes and i iterates when i finds a non zero
we swap i and j and increment j and i(which is already incrementing)
Time complexity O(N)
space O(1)
*/
void zeropti( vector<int>&v )
{
  int j=-1;
for(int i=0;i<v.size();i++)
{
    if(v[i]==0)
    {
        j=i;
        break;//setting j on fisrt zero
    }
}
if(j==-1){ return; }//no zeroes return
//now we will start i from j+1
for(int i=j+1;i<v.size();i++)
{
    if( v[i]!=0 )
    {
        swap(v,i,j);
        j++;
    }
}

}
int main()
{
vector<int> v={1,2,0,23,0,5,0,4,6,6,6,6};

zeropti(v);
printv(v);
}
