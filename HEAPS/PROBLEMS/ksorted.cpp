#include <bits/stdc++.h>
using namespace std;
/*
You are given an array where each element is at
most k positions away from its sorted position. What is
the most efficient way to sort this array?
*/
void VectorCout(vector<int> v)
{
    for (auto it : v)
    {
        cout << " " << it << " ";
    }
    return;
}

void F(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for (int i = 0; i <= k; i++)
    {
        pq.push(v[i]);
    }
    int index = 0;
    for (int i = k + 1; i < v.size(); i++)
    {
        v[index] = pq.top(); // min element
        pq.pop();
        index++;
        pq.push(v[i]);
    }
    while (!pq.empty())
    {
        v[index] = pq.top();
        pq.pop();
        index++;
    }
    return;
}

int main()
{
    vector<int> v = {1, 4, 3, 2, 6, 5};
    F(v, 2);
    VectorCout(v);
}
