#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int> &nums)
    {
        int n = nums.size();
        vector<ll> copy(n);
        for (int i = 0; i < n; i++)
        {
            copy[i] = (ll)nums[i];
        }

        int badPairs = 0;
        vector<int> nextIndex(n);
        vector<int> prevIndex(n);
        set<pair<ll, int>> st; // {  {sumOfPairs,indexOfFirstElementOfThePair }  }

        for (int i = 0; i < n - 1; i++)
        {
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
            if (copy[i] > copy[i + 1])
            {
                badPairs++;
            }
            st.insert({copy[i] + copy[i + 1], i});
        }
        nextIndex[n - 1] = n;
        prevIndex[n - 1] = n - 2;
        int ans = 0;
        while (badPairs)
        {
            ll minSum = st.begin()->first;
            int firstIndex = st.begin()->second;
            int secondIndex = nextIndex[firstIndex];
            int secondRight = nextIndex[secondIndex];
            int firstLeft = prevIndex[firstIndex];
            // update prevIndex and frontIndex array
            // update bad pairs

            if (copy[firstIndex] > copy[secondIndex]) // we are about to remove a bad pair
            {
                badPairs--;
            }

            if (firstLeft >= 0 && copy[firstLeft] <= copy[firstIndex] && minSum < copy[firstLeft]) // we are about to remove a good pair and add a bad pair
            {
                badPairs++;
            }

            else if (firstLeft >= 0 && copy[firstLeft] > copy[firstIndex] && minSum >= copy[firstLeft]) // we are about to remove a bad pair and insert a good pair
            {
                badPairs--;
            }
            if (secondRight < n && copy[secondRight] >= copy[secondIndex] && minSum > copy[secondRight]) // we are about to remove a good pair and add a bad pair
            {
                badPairs++;
            }
            else if (secondRight < n && copy[secondRight] < copy[secondIndex] && minSum <= copy[secondRight]) // we are about to remove a bad pair and insert a good pair
            {
                badPairs--;
            }
            // update set
            st.erase({minSum, firstIndex});
            if (firstLeft >= 0)
            {
                st.erase({copy[firstLeft] + copy[firstIndex], firstLeft});
                st.insert({minSum + copy[firstLeft], firstLeft});
            }
            if (secondRight < n)
            {
                st.erase({copy[secondIndex] + copy[secondRight], secondIndex});
                st.insert({minSum + copy[secondRight], firstIndex});
            }
            // update next and prev vectors
            copy[firstIndex] = minSum;
            nextIndex[firstIndex] = secondRight;

            if (secondRight < n)
            {
                prevIndex[secondRight] = firstIndex;
            }
            ans++;
        }
        return ans;
    }
};