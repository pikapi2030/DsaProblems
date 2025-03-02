#include <iostream>
#include <vector>
#include <set>
using namespace std;
// give union of two sorted arrays in an array
void setprint(set<int> s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << " ";
    }
}

void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
}

/*
BRUTE use a set
t.c  O( n1*logN+ n2*logN )+O(n1+n2)
n1,n2 -size of v1and v2
N- size of set
space complexity O(n1+n2)//size of set worst case +O(n1+n2)//size of vector we return worst
case

vector<int> uniobrute(vector<int>&v1,vector<int>&v2)
{
    set<int>st;
    for( auto it=v1.begin();it!=v1.end();it++ )
    {
        st.insert(*(it));
    }
        for( auto it=v2.begin();it!=v2.end();it++ )
    {
        st.insert(*(it));
    }
    vector<int>v3;
    for( auto it:st )
    {
        v3.push_back(it);
    }
  return v3;
}

int main()
{
    vector<int>v1={ 1,2,3,4,5};
    vector<int>v2={3,4,5,6,7,0,8};
    uniobrute(v1,v2);
}

*/
/*
in optimal solulu we use two pointer i and j
if v1[i]>v2[j] we add v2[j] in our union array and increment i
 vice versa
till one of the pointer reach the end then the remaining pointer is made to
reach the end stroing all elements of other arra if no added
time complexity
O(n1+n2)
space complexity O(n1+n2) only for returning the ans

*/

void unionopti(vector<int> &v1, vector<int> &v2)
{
    vector<int> v3;
    int i=0, j = 0;
    
    while (i < v1.size() && j < v2.size())
    {     

        if (v1[i] >= v2[j])
        { 
            if (  v3.empty() ||v3.back() != v2[j])
            {
                v3.push_back(v2[j]);
                
            }
            j++;
        }

        else if (v2[j] > v1[i])
        { 
            if ( v3.empty() ||v3.back() != v1[i] )
            {
                v3.push_back(v1[i]);
                
            }
            i++;
        }
    }
   
        while (i < v1.size())
        {
            {
                if (v3.back() != v1[i] || v3.empty() )
                    v3.push_back(v1[i]);
            }
            i++;
        }


          while (j < v2.size())
        {
            {
                if (v3.back() != v2[j] || v3.empty() )
                    v3.push_back(v2[j]);
            }
            j++;
        }
        
      printv(v3);
      
      }

int main()
{ 
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7, 0, 8};
    unionopti(v1, v2);
}
