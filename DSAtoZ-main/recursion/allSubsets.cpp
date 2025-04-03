#include <bits/stdc++.h>
using namespace std;
/*
printing all subsets or subsequences is the same thing if elements in array are unique
*/

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
