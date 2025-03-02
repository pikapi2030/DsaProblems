#include <bits/stdc++.h>
using namespace std;
/*
find leader
 leader is an element in an array which is greater than all elements present right to it
 there can be more than one leaders
*/
void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
}

/*
brute force
2 nested loops checking if i is leader
 T.C near about O(N^2)
 S.C O(N) is ans array is considered 

*/

vector<int> leaderbrute(vector<int> &v)
{
    vector<int> ans;
    int flag;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        flag=1;
        for (int j = i ; j < n; j++)
        {
            
            if (v[j] > v[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

/*
OPTIMAL 
we start from back and maintain a max element, if v[i]>max, v[i] is leader and max updated
to v[i]
T.C O(N)
S.C O(N) is ans is considered
*/

vector<int>leaderopti(vector<int>v)
{
    int n=v.size();
    int max=INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
     if(v[i]>max)
     {
        
        ans.push_back(v[i]);
        max=v[i];
     } 
    }
return ans;
}

int main()
{
    vector<int>v={1,2,3,4};
    printv(leaderopti(v));
}