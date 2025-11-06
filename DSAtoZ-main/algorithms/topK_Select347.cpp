#include <bits/stdc++.h>
using namespace std;
class Solution1
{
public:
    int lomutoPartion(vector<int> &v, int low, int high, unordered_map<int, int> &mp)
    {

        int storeIndex = low; // it holds  indexs of a larger value than pivot, which will be swapped when we find a smaller value
        int pivot = v[high];
        for (int i = low; i < high; i++) // high is pivot, so we do not traverse till high,but high-1
        {
            if (mp[v[i]] <= mp[pivot]) // found smaller, swap with larger(held by swapIndex)
            {
                swap(v[storeIndex], v[i]);
                storeIndex++;
            }
        }
        swap(v[storeIndex], v[high]);
        return storeIndex;
    }

    // ---------- QuickSelect ----------
    void quickSelect(vector<int> &v, int low, int high, int k, unordered_map<int, int> &mp)
    {
        int n = v.size();
        if (low < high)
        {
            int partition = lomutoPartion(v, low, high, mp);
            if (partition == n - k)
            {
                return;
            }
            else if (partition > n - k)
            {
                quickSelect(v, low, partition - 1, k, mp);
            }
            else // partion <n-k
            {
                quickSelect(v, partition + 1, high, k, mp);
            }
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        for (int it : nums)
        {
            mp[it]++;
        }
        vector<int> keys;
        for (auto it : mp)
        {
            keys.push_back(it.first);
        }
        int n = keys.size();
        quickSelect(keys, 0, keys.size() - 1, k, mp);
        return vector<int>(keys.begin() + n - k, keys.end());
    }
};

class Solution2
{
public:
    vector<int> heapSolve(vector<int> &keys, int k, unordered_map<int, int> mp)
    {
        // a comp variable which stores lambda function
        auto comp = [&mp](int a, int b)
        {
            return mp[a] > mp[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp); // syntax: priority_queue<T,underlyingContainer<T,typeOfcomparatorFunction>name
        // decltype tells compilers type of comparator at compileTime
        for (int i = 0; i < keys.size(); i++)
        {
            pq.push(keys[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        // now our pq contains most-freq k elements
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            int top = pq.top();

            pq.pop();
            ans.push_back(top);
        }
        return ans;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int it : nums)
        {
            mp[it]++;
        }
        vector<int> keys;
        for (auto it : mp)
        {
            keys.push_back(it.first);
        }
        return heapSolve(keys, k, mp);
    }
};