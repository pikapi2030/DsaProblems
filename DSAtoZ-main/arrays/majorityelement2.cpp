#include <bits/stdc++.h>
using namespace std;
/*
given a vector of size n
return a list with elements occuring more than n/3 times(majority element)
*/
// note: maximum number of majority elements can be 2 only(does not varies on n)
/*BRUTE
we make ans vector which at max will contain 2 elements
traverse and if list is empty or curent element in list is not same is v[i]
we keep a counter to count frequency of element and add the element
if cnt>n/3

T.C O(n^2)
S.C O(2)
*/
vector<int> majorbrute(vector<int> v)
{
    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0 || ans[0] != v[i]) // only two majority, so if one is already we..
        // ..should not check it again
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (v[i] == v[j])
                {
                    cnt++;
                }
            }
            if (cnt > n / 3)
            {
                ans.push_back(v[i]);
            }
        }
        if (ans.size() == 2)
        {
            return ans;
        } // since only two majority can be possible
    }
}

/*BETTER
using hashmap

 T.C O(n*log n)
 s.c O(n)(of map)

*/

vector<int> majorbetter(vector<int> v)
{
    vector<int> ans;
    int n = v.size();
    map<int, int> mp;
    int minfreqformajor=n/3 +1;//the minimum freq required to be a major element
    for (int i = 0; i < n; i++)
    {

        mp[v[i]]++;
        if (mp[v[i]] == minfreqformajor)//== cause once the num is added, > would add the num once again
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

/*OPTIMAL SOLUTION
 BOYER's MOORE's voting algorithm(EXTENDED version of moore's)
 T.C O(2n)
 S.C O(1) 
*/
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

