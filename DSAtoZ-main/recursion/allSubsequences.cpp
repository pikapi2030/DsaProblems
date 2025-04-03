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

/*aproach
we use pick , not pick aproach
F(temp,i) indicates that this function will call two function 
in one it will push the ith index in temp, 
in other one it will not push the ith index in temp(basically pop it by backtracking)
F(temp,i) will call F(temp,i+1) in both cases, but temp will be different of both cases
here the index i does not represent size of temp in anyway

the recursion tree of this code is a binary tree
example {1,2,3}

                                            F({},0)
                    F({1},1)                                         F({},1)
        F({1,2},2)              F({1},2)                   F({2},2)           F({},2)   
F({1,2,3},3) F({1,2},3)   F({1,3},3)  F({1},3)      F({2,3},3) F({2},3)   F({3},3) F({},3)                                 F({},3)

output: 123 12 13 1 23 2 3 
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
