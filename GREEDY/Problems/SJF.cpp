#include <bits/stdc++.h>
using namespace std;
/*
Geek is a software engineer. He is assigned with the task of calculating average waiting time 
of all the processes by following shortest job first policy.

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the 
waiting process with the smallest execution time to execute next.

Given an array of integers bt of size n. Array bt denotes the burst time of each process. 
Calculate the average waiting time of all the processes and return the nearest integer which 
is smaller or equal to the output.

Note: Consider all process are available at time 0.
*/


long long solve(vector<int>& bt) 
{
int n=bt.size();
int totalWaitingTime=0;
int curTime=0;
sort(bt.begin(),bt.end());
for(int i=0;i<n;i++)
{
    
    totalWaitingTime+=curTime;
    curTime+=bt[i];
    
}
cout<<totalWaitingTime<<endl;
return totalWaitingTime/n;

}
int main()
{
    vector<int>v={1,2,3,4,7};
    cout<<solve(v);
}

