#include <bits/stdc++.h>
using namespace std;

/*
find a pair of elements in array which add up to given k
if exists return indexes of the pairs
*/

/*
BRUTE FORCE
using two for loop
T.C  slightly less than O(n*n)
*/

vector<int> twobrute(vector<int> v, int k)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == k)
            {
                return {i, j};
            }
        }
    }
}

/*
better solution
using hashing,we store the value as key and index as value(in map)
if we find an element in map which satifies the condition k-v[i]= element in map
then the element and v[i] for a pair
same technique used in subarray sum

T.C O(Nlog(n)) DEPENDS ON TYPE OF MAP
S.C O(N)
*/
vector<int> twobetter(vector<int> v, int k)
{
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        int rem = k - v[i];
        if (mp.find(rem) != mp.end())
        {
            if (i != mp[v[i]]) // to prevent returning same pairs when k=0
                return {i, mp[rem]};
        }
        mp[v[i]] = i; // THIS SHOULD BE AT LAST,FOR TO WORK WITH DUPLICATES
    }
}

/*
optimal solution
only for when we need to return yes or no if the pair exists
two pointer aproach
we sort the array and put one pointer at start and other at end useing i,j
v[i]+v[j]>k that means we have to move end poiter to the left to decrease the value
if v[i]+v[j]<k that means we have to move start pointer to right to increas the value
if v[i]+v[j]==k; return yes

T.C O(N)//loop   +O(NlogN)//for sorting
*/

int twooptimal(vector<int> v, int k)
{
    int i = 0, j = v.size() - 1;
    sort(v.begin(), v.end());

    while (i < j)
    { 
        int sum=v[i]+v[j];
        if (sum == k)
        {
            return 1;
        }
        if (sum < k)
        {
            i++;
        }
        if (sum>k)
        {
            j--;
        }
    }
    return 0;
    
}
int main()
{
    vector<int>v={575, 330, 339, 584, 239, 31, 173, 929, 967 };
    cout<<twooptimal(v,204);
}