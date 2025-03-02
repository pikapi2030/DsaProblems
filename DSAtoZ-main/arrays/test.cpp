#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    K is our target

    why is this quetion cannot we solved using two pointers(sliding window) like quetion number 209?
    beacuse in problem 209, nums had only positives numbers
    THIS PROBLEM HAS NEGATIVES AS WELL!!

    why are negative a problem?
    two pointer aproach only work when we are certain that if I move my left ahead my sum would decrease and if i mive my right ahead, my sum would increase
    only works when cumulative sum is in a monotonic order

    We can solve this quetion using prefix sum, hashmap

    prefixsum-x>=target, here x are keys in maps, x actually is sum till i, prefix sum is sum till j, so nums[j]-sum[i]>=k
    prefixSum-target>=x
    so if we find an x less than or equal to prefixSum-target, this means there is a subarray with sum atleas k, we record its length by doing ans=min(ans,j-i+1);

    The problem with this is to find something less than or equal to in a map,  takes Log(n) time(it is a AVLOR RED-BLAC TREE)

    So T.C is O(N*logN)

    a better option is deque,  takes O(1)(different aproach)

    in this quetion we will use a deque, why?

    why deque:-
    we need a ds that can remove element from back and front? but why?
    -----------------------------------------------------
    need of back removal:-
    we are trying to maintain a monotonic order of cumulative sum, if our current sum is less than back than we pop the back till our current some is equal or greater
    or till dqueue is empty

    why monotonic order?:- so that two pointer works
    -----------------------------------------------------
    need of front removal:-
    since we are using two pointer, first we will precompute commulative sum (in a monotonic order) till end of the nums
    then we will start our i from back of the queue, our window currently is front to back, we will try to shrink this window by bringing i closer to back
    and checking if cummulative sum is at leas k, if it is we will record the new size(new minimised size)

    */

    int shortestSubarray(vector<int> &nums, int k)
    {
        int minLen = INT_MAX;
        deque<pair<int, int>> dq; //{ index,cumulativeSum }
        int cumulativeSum = 0;

        for (int i = 0; i < nums.size(); i++) // BULDING A MONOTONIC CUMULTIVE SUM DEQUE
        {

            cumulativeSum += nums[i];
            if (cumulativeSum >= k)
            {
                minLen = min(minLen, i + 1);
            }
            pair<int, int> pr={INT_MIN,INT_MIN};

            // Compressing our window(if possible)(moving left ahead)
            while (!dq.empty() && cumulativeSum - dq.front().second >= k)
            {
                pr = dq.front();
                dq.pop_front();
            }
            // compareing last popped pair lenght with ans
            if(pr.first!=INT_MIN)
            {
            minLen = min(minLen, i - pr.first );
            }
            // moving right forward by building a monotonic cumulativeSum dq

            if (cumulativeSum < dq.back().second)
            {
                while (dq.back().second < cumulativeSum && !dq.empty())
                {
                    dq.pop_back();
                }
            }
            dq.push_back({i, cumulativeSum});
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};