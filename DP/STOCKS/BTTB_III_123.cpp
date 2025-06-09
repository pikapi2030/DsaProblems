#include <bits/stdc++.h>
using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).
Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging
multiple transactions at the same time. You must sell before buying again.
Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*aproach
we use a cnt variable determining state of transaction
0: first buy
1: first sell
2:second buy
3:third sell
*/
int F(vector<int> &p, int index, int cnt)
{

   if (index == p.size() || cnt == 4)
   {
      return 0;
   }
   int profit = 0;
   if (cnt % 2 == 0) // we can buy
   {
      profit = max(F(p, index + 1, cnt + 1) - p[index], F(p, index + 1, cnt));
   }
   else if (cnt % 2 != 0) // we can sell
   {
      profit = max(F(p, index + 1, cnt + 1) + p[index], F(p, index + 1, cnt));
   }
   return profit;
}
int Brute(vector<int> &p)
{
   return F(p, 0, 0);
}
//tabulation
int maxProfit(vector<int> &p)
{
   int n = p.size();
   vector<vector<int>> dp(n + 1, vector<int>(5, 0)); // 0 indexed,n+1 cause base case
   for (int i = n - 1; i >= 0; i--)
   {
      for (int j = 3; j >= 0; j--)
      {
         if (j % 2 == 0) // buy
         {
            dp[i][j] = max(dp[i + 1][j + 1] - p[i], dp[i + 1][j]);
         }
         else // sell
         {
            dp[i][j] = max(dp[i + 1][j + 1] + p[i], dp[i + 1][j]);
         }
      }
   }
   return dp[0][0];
}
