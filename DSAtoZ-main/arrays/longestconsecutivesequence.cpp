#include <bits/stdc++.h>
using namespace std;
/*
given an array
output lenght of longest consecutive sequence
arr[]={1,5,7,9,2,20,3}
ans =1,2,3 so three is the length
*/

/*
BRUTE
iterate thorught aray picking each element and finding its consecutive
maintain a maxl, cnt and x, x=v[i] if consecutive found, x=x+1, cnt++
maxl=max(maxl,cnt);
T.C O(n^3)
S.C O(1)
*/

int ispresent(vector<int> v, int k)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == k)
        {
            return 1;
        }
    }
    return 0;
}

int longestbrute(vector<int> v)
{
    int n = v.size();
    int x, cnt = 0, maxl = 0;
    for (int i = 0; i < n; i++)
    {
        x = v[i];

        while (ispresent(v, x))
        {
            x = x + 1;
            cnt++;
        }
        maxl = max(maxl, cnt);
        cnt = 0;
    }
    return maxl;
}

/*
BETTER
use sorting and maintain a presmallest element,a counter and maxl
if v[i]!=small
presmall=v[i]

ifv[i]-1==small
cnt++
T.C O(NlogN)+O(N)
*/

int longestbetter(vector<int> v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    int presmall = INT_MAX;
    int maxl = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {

        if (v[i] - 1 == presmall)
        {
            cnt++;
            presmall = v[i];
        }
        else if (v[i] != presmall)
        {
            maxl = max(maxl, cnt);
            cnt = 1;
            presmall = v[i];
        }
        maxl = max(maxl, cnt);
    }
    return maxl;
}

/*
optimal
we use a  unordered set dataset
we store elements of array in our set and maintain a start, if start-1 is present in set
then start can not be starting of the sequence, if start-1 is not present
then start is starting of our sequencing

T.C st.insert take O(1) for average and best  and O(N) in worst(collison case)
so assuming it take O(1)
T.C=  O(1*N)(st.insert loop)  +O(2N) (check urself) the while loop inside does 
not runs for N iterations

*/
int longestopti(vector<int> v)
{
    int maxl = 0;
    int n = v.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(v[i]);
    }
    for (auto it : st)
    {
        int cnt;
        if (st.find(it - 1) == st.end())
        {

            int x = it;
            int cnt = 1;

            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt++;
            }
            maxl = max(cnt, maxl);
        }
    }
    return maxl;
}
