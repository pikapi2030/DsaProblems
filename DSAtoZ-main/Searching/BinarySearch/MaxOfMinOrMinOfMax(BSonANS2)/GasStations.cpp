#include <bits/stdc++.h>
using namespace std;
/*
given a sorted gas station array v and a int k,
v[i] represents position of ith gas station
we have to place k gas stations in the array such that THE MAXIMUM DISTANCE BETWEEN TWO CONSECUTIVE
GAS STATIONS IS MINIMUM

NOTE: MINIMUM DISTANCE CAN BE IN DOUBLES
*/

/*BRUTE FORCE

let's say k=4, v={1,13,17,23}

now our main goal is to reduce distance between consecutive gas station
so it would make sense that we should place our gastation where there is
maximum gap between two consecutive gas stations

max gap is between 1 and 13 so we place our first gas staion between them
we also should place in the middle of both (other wise one side woul be larger)

so v={1,7,13,17,23}
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION

now the max distance is between 17 and 23 or 1,7 or 7, 13
lets place our second gas station  at 17,23

v={1,7,13,17,20,23}
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION


NOW max distance is 6 between 1,7 or 7,13
BUT WE WILL NOT PLACE BETWEEN ANY OF THOSE,(IF WE DO MAX DIST WIIL STILL BE 6 DUE TO ONE SIDE)
SO WE MOVE OUR 7(IST GAS STATION), so now we have 2 gas station to place between 1,13

we will place them equally having 4 distance in between
v={1,5,9,13,17,20,23}
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION

we will countinue untill we place the last gas station then we will
calulate tha max distnace between two consecutive gas stations and return it

to actually implement this we will use a an outer for going from 1 to k
at every iteration the loop places the gas sation

we will use another(nested) for loop to actually place the stations
we will maintain a HowManyPlaced array whoose size would be v.size()-1

HowManyPlaced array represents the gap between the gas staions
and is initialized with 0 at every indexed
the index represents number of new gas stations placed between the two consecutive gas
stations (0th index represents gap between first two gas sttions and so on)

so if v={1,10,20}
HowManyPlaced=[0,0]  (initialy 0 gastations between 1,10 and between 10,20)
if we place a gas staion between 10,20  then our array will become
v={1,10,15,20}
 and HowManyPlaced=[0,1] the 1 indicates the number of gas station placed
between 10,20

this is important to calculate the  dist between two consecutive gas station
in order to decide where to place the next gas station

WE WILL ALSO MAINTAIN A VARIABLE(WhereMAX) WHICH WILL
STORE THE INDEX WHERE DIST BETWEEN TWO GAS STAION IS MAX


dist=v[i+1]-v[i]/(HowManyPlaced[i]+1)  which for i=1 comes to be 5
NOTE: WE ARE NOT ACTUALY MODIFYING OUR V, IT IS ONLY FOR DEMOSTRATION

since we can calculate dist for every i, we can decide where to place our next gas station
simply by doing HowManyPlaced[WhereMax++] WhereMax stores the index of max dist

after placing k gas station we will calculate max dist one last time to return it

T.C O(k*n+n)

*/

double BRUTE(vector<int> v, int k)
{
    vector<int> HowManyPlaced(v.size() - 1, 0); // a vector of size v.size()-1, initialized with 0
    for (int gastations = 1; gastations <= k; gastations++)
    {
        long double maxdist = -1;
        int maxdistWHERE = -1;

        for (int i = 0; i < v.size() - 1; i++)
        {
            long double dist = ((double)v[i + 1] - (double)v[i]) / ((double)HowManyPlaced[i] + 1);
            if (dist >= maxdist)
            {
                maxdist = dist;   // updates maxdist
                maxdistWHERE = i; // updates location of maxdist
            }
        }
        HowManyPlaced[maxdistWHERE]++; // placing the gas staion where maxdist is located
    }
    // running another non-nested loop to find maxdist between gas consecutive staions(to return)
    long double ans = -1;
    for (int i = 0; i < v.size() - 1; i++)
    {
        long double dist = ((double)v[i + 1] - (double)v[i]) / ((double)HowManyPlaced[i] + 1);
        ans = max(ans, dist);
    }
    return ans;
}

/*BETTER

we will a priority queqe of pair data type
a priority queqe keeps maximum value at the top

first will store dist, second will store index(the location of dist)

we run a loop from i=0 to i=v.size()-1 to store
dist between gastations and there indexes

then we run our 1 to k loop
in which we store our top pair(the pair with max dist, here we have to place a gas station)
in a tp variable(pair data type),
 do HowMany[tp.second()]++(second stores the index of max dist)
and pop the top pair from our queqe(in order to update the new max dist,
other wise this will always remain the max dist)

as we know tp.second represents the location of max dist
now we add our new dist (after adding the gas station ) to queqe, in next iteration
new dist can become max dist
new_dist=(v[tp.second+1]-v[tp.second])/(HowMany[tp.second]+1)
calculating the new distance by dividing old distace with number of gastations in between

at the end just return the top pair's distance(first) as it will be the max dist b/w two
consecutive gas stations hence our ans

T.C  it take log N for push to work(one time)
so T.C is O(NlogN)+O(klogN)
S.C O(n-1) (because of queqe)
*/

double BETTER(vector<int> v, int k)
{
    vector<int>HowMany(v.size()-1,0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < v.size() - 1; i++)
    {
        pq.push({v[i + 1] - v[i], i}); // adding gaps between consecutive stations and their indexes
    }

    for(int gastation=1;gastation<=k;gastation++)
    {
        auto tp=pq.top();//auto becomes a pair data type
        pq.pop();
        HowMany[tp.second]++;//tp.second stands for location of the gap
        long double NewDist=((double)v[tp.second+1]-(double)v[tp.second])/((long double)HowMany[tp.second]+1);
        pq.push({NewDist,tp.second});//adding new smaller dist at the location where we added our new station
    }
    return pq.top().first;
}
