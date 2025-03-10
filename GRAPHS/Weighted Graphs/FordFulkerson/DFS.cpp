#include <bits/stdc++.h>
using namespace std;

int dfs(int start, int sink, vector<vector<int>> &residual, vector<int> &vis, int flow)
{
	if (start == sink)
	{
		return flow;
	}
	vis[start]=1;
	for (int i = 0; i < residual.size(); i++)
	{
		if (residual[start][i] > 0 && !vis[i])
		{
			int newflow = min(flow, residual[start][i]);
			vis[i] = 1;
			int bottleNeck =  dfs(i, sink, residual, vis, newflow);
			if (bottleNeck > 0)
			{
				residual[start][i] -= bottleNeck;
				residual[i][start] += bottleNeck;
				return bottleNeck;
			}
		}
	}
	return 0;
}

int fordFulkerson(vector<vector<int>> &graph, int sink, int source)
{
	int n = graph.size();
	vector<vector<int>> residualGraph = graph;
	int maxFlow = 0;
	
	while(true)
	{
		vector<int>vis(n,0);
		int flow=dfs(source,sink,residualGraph,vis,INT_MAX);
		if(flow==0)
		{
			break;
		}
		maxFlow+=flow;
	}
	return maxFlow;
}

int main()
{
	int n;
	cout<<"Enter size:-";
	cin>>n;
	vector<vector<int>>v(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER ROW:"<<endl;
		for(int j=0;j<n;j++)
		{
         cin>>v[i][j]; 
		 
		}
	}
	cout<<fordFulkerson(v,2,0);
}
