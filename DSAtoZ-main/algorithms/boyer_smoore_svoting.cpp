#include<bits/stdc++.h>
using namespace std;
/*
this is and extended version of moore's voting
it gives elements whose freq>n/3
*/

/*
instead of only using one cnt and one element var here we use 2 counters and 2 elements var
considered as majority(maximum majority elements can only be 2 in case of n/3)
*/

/*
T.C O(2n)
S.C O(1)
*/
void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
}

vector<int>BMV(vector<int>v)
{
    int n=v.size();
    int cnt1=0,cnt2=0,el1=INT_MAX,el2=INT_MAX;
    vector<int>ans;
    int minfreqformajor=(int)(n/3)+1;//n/3 typecasted to int
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && v[i]!=el2)//second condition to make sure el1 and and el2 are unique
        {
            cnt1=1;
            el1=v[i];
        }
        else if(cnt2==0&&v[i]!=el1)
        {
            cnt2=1;
            el2=v[i];
        }
        else if(v[i]==el1)
        {
            cnt1++;
        }
        else if(v[i]==el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    //perform manual check since we are not sure if there are 0, 1 or 2 number of majors
    cnt1=0,cnt2=0;//setting 0 to perform manual check(don't wana use extra vars)
    for(int i=0;i<n;i++)
    {
        if(v[i]==el1)
        {
            cnt1++;
        }
        if(v[i]==el2)
        {
            cnt2++;
        }
    }
    if(cnt1>=minfreqformajor)
    {
        ans.push_back(el1);
    }
    if(cnt2>=minfreqformajor)
    {
        ans.push_back(el2);
    }

    return ans;
    }
    
    int main()
    {
        vector<int>v={3,2,3};
        printv(BMV(v));
    }
    
    
