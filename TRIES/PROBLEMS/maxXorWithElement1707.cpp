#include <bits/stdc++.h>
using namespace std;

/*
You are given an array nums consisting of non-negative integers. You are also given a queries
array, where queries[i] = [xi, mi].
The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that
does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that
nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
Return an integer array answer where answer.length == queries.length and answer[i] is the
answer to the ith query.
Example 1:
Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2.
The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:
Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
*/

/*aproach
we sort nums, we sort queries according to limit(querie[i][1])
but since we need answer according to order of queri we create offline queries
which basically means queries with order changed but orignal index stored as well
we traverse offline queries, we insert numbers in trie until we reach greater than
limit of current query, then we calculate maxXor and store in ans vector,
ans[orignal saved index ]=maxXor calculated by trie data structure
*/

class Node
{
public:
    Node *link[2]; // stores 0 or 1
    Node()
    {
        link[0] = NULL;
        link[1] = NULL;
    }
    bool isPresent(int bit)
    {
        return link[bit] != NULL; // bit not NULL there it is there
    }
    void put(int bitToPut, Node *node) // will pass a new node
    {
        link[bitToPut] = node;
    }
    Node *getAddress(int bit)
    {
        return link[bit];
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node;
    }

    void insert(int num)
    {
        Node *temp = root;
        for (int i = 30; i >= 0; i--)
        {
            int ithBit = (num >> i) & 1;
            if (!temp->isPresent(ithBit))
            {
                temp->put(ithBit, new Node);
            }
            temp = temp->getAddress(ithBit);
        }
    }
    int maxXor(int num)
    {
        int ans = 0;
        Node *temp = root;
        for (int i = 30; i >= 0; i--)
        {
            int ithBit = (num >> i) & 1;
            int inverseBit = 1 - ithBit;
            if (temp->isPresent(inverseBit))
            {
                // set ith bit of ans=1;
                ans = (1 << i) | ans;
                temp = temp->getAddress(inverseBit);
            }
            else
            {
                temp = temp->getAddress(ithBit); // since inverse bit is not pressent, ith bit will be present
            }
        }
        return ans;
    }
};

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
    Trie tr;
    int numsIndex = 0; // index pointing to nums
    vector<int> ans(queries.size());

    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> offlineQueries; // queries with orignal indexes
    for (int i = 0; i < queries.size(); i++)
    {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());

    for (auto it : offlineQueries)
    {
        int upperLimit = it.first;
        int num = it.second.first;
        int orginalIndex = it.second.second;
        while (numsIndex < n && nums[numsIndex] <= upperLimit)
        {
            tr.insert(nums[numsIndex]);
            numsIndex++;
        }
        if (numsIndex == 0)
        {
            ans[orginalIndex] = -1;
        }
        else
        {
            ans[orginalIndex] = tr.maxXor(num);
        }
    }
    return ans;
}
