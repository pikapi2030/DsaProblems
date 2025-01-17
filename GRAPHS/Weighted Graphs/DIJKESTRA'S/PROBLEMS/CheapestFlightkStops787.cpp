#include <bits/stdc++.h>
using namespace std;

/*WHY QUEUE AND NOT PQ?
when we use pq, it sort according to price, but price is not our stop priority
it is number of stops, we want minimum price, but with number of stops should
also not exceed the given k, so top priority is number of stops
//!we can use a pq sorting according to number of stops, 
//!but number of stops increase uniformly(equally at every node,(weight =1))
so a normal queue will also keep pair in a sorted order(wrt uniformly increaing quantity)
*/

/*
There are n cities connected by some number of flights.
You are given an array flights where flights[i] = [fromi, toi, pricei]
indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price
from src to dst with at most k stops. If there is no such route, return -1.
*/

/*aproach
convert given data to adj list
us dijk algo
//!but not with queue not pq
*/

int sol(int n, vector<vector<int>> flights, int src, int dst,int k)
{
    vector<vector<pair<int, int>>> adjL(n); //{{dest,price},{},{}   }
    for (auto it : flights)
    {
        adjL[it[0]].push_back({it[1], it[2]});
    }
    //!{total_price_till_now_to_reach_this_dest ,{dest,total_stops}}
    queue<pair<int,pair<int,int>>>pq;
    vector<int> minPrice(n, INT_MAX);
    pq.push({0, {src, 0}});
    while(!pq.empty())
    {
        int price=pq.front().first;
        int node=pq.front().second.first;
        int stops=pq.front().second.second;
        pq.pop();
        for(auto it:adjL[node])
        {
            int newPrice=price+it.second;
            int newDest=it.first;
            if(minPrice[newDest]>newPrice&&stops<=k)
            {
                minPrice[newDest]=newPrice;
                pq.push({newPrice,{newDest,stops+1}});
            }
        }
    }
    if(minPrice[dst]==INT_MAX){return -1;}
    return minPrice[dst];
}
