#include <iostream>
#include <set>
using namespace std;
#include<vector>


// MODIFY ARRAY SUCH THAT IF IT HAS N UNIQUE ELEMENTS, IT'S FIRST N ELEMENTS MUST BE THOSE
// WE DON'T CARE ABOUT OTHER ELEMENTS
// also return the number of uique elements
/*
ex- a[]={1,1,2,2,2,3,3,3,3};
output a[]={1,2,3,,,,,,} first three must be unique baki ka we don't care about
*/
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i] << " ";
    }
}
/*
my solution cares about all elements

void remover(int arr[], int &n, int i)
{
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    n--;
}
void dupliremove(int arr[], int &n)
{
    int dupli=arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == dupli )
        {
            remover(arr, n, i);
            i--;
        }
        dupli = arr[i];
    }
}

int main()
{
    int size;
    cout << "ENTER SIZE:";
    cin >> size;
    int a[] = {1,1,1, 2,2,2,2,2,2,2,2,2,2,2,2,3};
    dupliremove(a,size);
    printarray(a, size);
}

*/
void printv(vector <int>a)
{
    for( auto it=a.begin();it!=a.end();it++  )
{
    cout<<*(it)<<" ";
    
}
cout<<endl;

}

// BRUTE FORCE
/*
using a set
time complexity O(NlogN+N)
NlogN for insert function , +N for for each loop
space complexity O(N), as set can contain all elements if unique(worst case)

void duplimodify(int arr[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int index=0;
for( auto it:s )//here auto becomes int and it represents the values, s represents the data set
 // we are going thorugh
{
  arr[index++]=it;
}
}

int main()
{   
    int size = 10;
    int a[] = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6};
    duplimodify(a,size);
    printarray(a, size);
    return 0;
}  
*/

//OPTIMAL
/*
int two pointer aprocach we keep i at starting and a j moving ahead if j founds someone 
diff then i then i incerements and then that someone goes to i
this process is looped until first n element of array are the n unique
time complexity:- O(N)
space complexity:- O(1)
*/
int dupliopti( vector <int> &arr )
{ int n=arr.size();
    int j=1;
int i=0;
    while( j<n )
    {
        if( arr[i]!=arr[j] )
        {
           ++i;
           arr[i]=arr[j];

        }
        j++;
    }
    return i+1;
}

int main()
{
    vector <int> a={1,1,2,4,4,4,6,6};
    cout<<dupliopti(a)<<endl;
    printv(a);
}