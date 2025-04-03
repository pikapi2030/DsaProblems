#include <bits/stdc++.h>
using namespace std;

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

void helper(vector<int> &v, vector<int> &temp, vector<vector<int>> &ans, int index, int n, int k)
{
    if (temp.size() > k)
    {
        return;
    }
    if (n < 0)
    {
        return;
    }
    if (n == 0 &&temp.size()==k)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i<v.size(); i++)
    {
        temp.push_back(v[i]);
        helper(v, temp, ans, i + 1, n - v[i], k);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> temp;
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> ans;
    helper(input, temp, ans, 0, n, k);
    return ans;
}

int main()
{
    int n=7;
    int k=3;
    matrixPrinter(combinationSum3(k,n));

}
