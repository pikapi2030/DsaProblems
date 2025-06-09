#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array prices where prices[i] is the price of a given stock on the 
ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve 
the maximum profit of 0.
*/
//!greedy aproach
int maxProfit(vector<int>& prices) 
{
int ans=0;
for(int i=0;i<prices.size()-1;i++)
{
if(prices[i]<prices[i+1])
{
    ans+=prices[i+1]-prices[i];
}
}
return ans;    

}

/*recursive aproach
F(index,canBuy)
if canBuy=1, we can Buy(means we have not bought yet) otherwise we sell first(bought already)
if(index==n){return 0;}
if(canBuy)
{
profit= max( F(index+1,0)-price[index],F(index+1,1)-0)//bought, not bought aproach
}
else//sell
{
protfit=max(F(index+1,1)+price[index],F(index+1,0))
}
return profit;
*/
int recur(vector<int>&p,int index,bool canBuy)
{
int profit=0;    
if(index==p.size())
{
    return 0;
}
if(canBuy)
{
profit=max(recur(p,index+1,0)-p[index],recur(p,index+1,1));
}
else
{
    profit=max(recur(p,index+1,1)+p[index],recur(p,index+1,0));
}
return profit;
}
int maxProfit(vector<int>& prices) 
{
    return recur(prices,0,1);
}




