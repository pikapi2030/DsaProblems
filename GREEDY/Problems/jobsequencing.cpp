#include <bits/stdc++.h>
using namespace std;
/*
You are given three arrays: id, deadline, and profit, where each job is associated with an ID,
a deadline, and a profit. Each job takes 1 unit of time to complete,
and only one job can be scheduled at a time. You will earn the profit associated with a
job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.

Examples :

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30)
*/

void VectorOfpairPrint(vector<pair<int,int>>v)
{
    for(auto it:v)
    {

    cout<<" {"<<it.first<<","<<it.second<<"}"<<" ";
    cout<<endl;

    }
}

int MaxOfVector(vector<int>v)
{
    int ans=INT_MIN;
    for(auto it:v)
    {
        ans=max(ans,it);
    }
    return ans;
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
{
    int n = profit.size();
    vector<pair<int, int>> combine;
    for (int i = 0; i < n; i++)
    {
        combine.push_back({profit[i], deadline[i]});
    }
    sort(combine.rbegin(), combine.rend());//desending sort
    
    int sizeOfdays=MaxOfVector(deadline);
    vector<int>hashDays(sizeOfdays+1,-1);//1 indexed
    int jobsDone=0;
    int ans=0;//total profit
    for(auto it:combine)
    {
        int profitt=it.first;
        int deadLinee=it.second;
        for(int i=deadLinee;i>0;i--)
        {
          if(hashDays[i]==-1)
          {
            hashDays[i]=0;//marked
            ans+=profitt;
            jobsDone++;
            break;
          }
        }
    }
    return {jobsDone,ans};
}

int main()
{
    vector<int>id={1,2,3,4};
    vector<int>deadline={4,1,1,1};
    vector<int>profit={20,1,40,30};
    vector<pair<int, int>> combine;
   

    
}