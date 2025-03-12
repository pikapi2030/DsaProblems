#include <bits/stdc++.h>
using namespace std;
/*
generate all subsequences of a given array
a subsequence is  in order part of an aray, may or may not be contagious(continious)
example:- 1,2,3
1
2
3
1,2
1,3
2,3
1,2,3
!3,1 is not a subsequence (not in the order of array)
*/
//! T.C O(2^N)  S.C O(N)
void matrixPrinter(const vector<vector<int>> &v)
{
   for(int i=0;i<v.size();i++)
   {
    for(auto it:v[i])
    {
        cout<<" "<<it<<" ";
    }
    cout<<endl;
   }
}

void helper(const vector<int> &v, vector<int> &temp, vector<vector<int>> &ans,int index)
{
    int n = v.size();
    if(index>=n)
    {
     ans.push_back(temp);
     return;
    }
    temp.push_back(v[index]);
    helper(v,temp,ans,index+1);//picked
    temp.pop_back();
    helper(v,temp,ans,index+1);//not picked
}

vector<vector<int>> allSubsequences(const vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> ans;

    vector<int> temp;
    helper(v, temp, ans,0);
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3};
    matrixPrinter (allSubsequences(v));
}
