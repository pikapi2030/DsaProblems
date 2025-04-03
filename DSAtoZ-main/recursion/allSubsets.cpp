#include <bits/stdc++.h>
using namespace std;
//!input array only has unique elements
//same as printing all susequences, so allsubsequences code can also be used
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



void helper(vector<int> &v, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    if (index == v.size())
    {
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        temp.push_back(v[i]);
        ans.push_back(temp);
        helper(v, temp, ans, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> allSubsets(vector<int>v)
{
    vector<int>temp;
    vector<vector<int>>ans;
    helper(v,temp,ans,0);
    return ans;

}

int main()
{
vector<int>v={1,2,3};
matrixPrinter(allSubsets(v));
}
