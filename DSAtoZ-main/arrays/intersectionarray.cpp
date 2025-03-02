#include<iostream>
#include<vector>
using namespace std;
void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
}


/*
 find intersection of two arrays
 intersection array is allowed to have duplicate elements,
 a1={1,2,2,3,3}
 a2={2,3,3}
 intersection={2,3,3}( 2 correspoiding to two, 3 to 3 , 3 to 3 ) 

*/

/*
T.C O(n1*n2)  n1,n2 size of vectors
S.C O(size of vis array) space used in solution only(not in returning)
*/

void interbrute(vector <int>a,vector<int>b)
{  
    vector<int>inter;
vector<int>vis(b.size(),0);//as visited vector with same size as b with every index value 0
    for(int i=0;i<a.size();i++)
    {
        for( int j=0;j<b.size();j++ )
        {
          if(a[i]==b[j]&&vis[j]==0)
          {
            inter.push_back(a[i]);
            vis[j]=1;
            break;
          }
     if(b[j]>a[i]){ break;//sorted arrays }
          }
         
    }
}
printv(inter);
}




/*
OPTIMAL
T.C O(n1+n2)
S.C( n1+n2 )  if ans is returned in vector
*/

void interopti( vector<int>a,vector<int>b )
{
    vector<int>itr;
    int j=0,i=0;
    while( i<a.size()&&j<b.size() )
    {
        if( a[i]==b[j])
        {
           itr.push_back(a[i]);
           i++;
           j++;
        }
        else if(a[i]>b[j] )
        {
            j++;
        }
        else//b[j]>a[i]
        {
             i++;
        }
    }
    printv(itr);
}

int main()
{

    vector<int> v1 = {1, 2, 3, 4, 5,9};
    vector<int> v2 = {0,3, 4, 5, 6,7, 7,8,9};
    interopti(v1, v2);
}
