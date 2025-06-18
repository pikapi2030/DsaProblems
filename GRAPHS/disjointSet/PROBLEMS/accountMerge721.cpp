#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> rank, parent, size;

    disjointSet(int n)
    {
        rank.resize(n + 1, 0); // n+1 works both of 1 based and 0 based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findPar(parent[u]); // with path compression
        /*when we find the ultimate parent, we perform path compression,
        parent[u]= ultimate parent found by the function =findpar(parent[u])
        (done while returning)
        */
    }

    void unionByRank(int u, int v)
    {
        int pu = findPar(u); // ult par of u
        int pv = findPar(v); // ult par of v
        if (pu == pv)        // already connected as ult parents are same
        {
            return;
        }
        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else // rank[pu]==rank[pv]
        {
            parent[pu] = pv; // can also connect other way does not matter
            rank[pv]++;      // when  connecting same rank, rank increases
        }
    }
    void unionBySize(int u, int v)
    {
        int pu = findPar(u); // ult par of u
        int pv = findPar(v); // ult par of v
        if (pu == pv)        // already connected as ult parents are same
        {
            return;
        }
        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else //(size[pv] >= size[pu])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    bool isConnected(int u, int v)
    {
        return findPar(u) == findPar(v);
    }
};

/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first
element accounts[i][0] is a name, and the rest of the elements are emails representing emails
of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person
if there is some common email to both accounts. Note that even if two accounts have the same
name, they may belong to different people as people could have the same name. A person can
have any number of accounts initially, but all of their accounts definitely have the same
name.

After merging the accounts, return the accounts in the following format: the first element of
each account is the name, and the rest of the elements are emails in sorted order.
The accounts themselves can be returned in any order.
Example 1:
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email
"johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by
other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'],
['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still
be accepted.
Example 2:
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co",
"Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co",
"Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co",
"Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co",
"Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
*/

/*approach
we will use a map (string->int), it will map emails to indexes(names)
if we find an email already present in map, then we will merge the index of email found
and mp[email] which is mapped to the earlier index
after this create a vector vector string which merges indexes with emails,
here the index is actual parent of emails
*/

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> mp;
    disjointSet dj(n);

    for (int i = 0; i < n; i++) // i=0 is name
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string email = accounts[i][j];
            if (mp.find(email) == mp.end())
            {
                mp[email] = i;
            }
            else
            {
                dj.unionBySize(i, mp[email]);
            }
        }
    }
    // now join indexes with strings(merge them)
    vector<vector<string>> merged(n);
    for (auto it : mp)
    {
        string email = it.first;
        int parentNode = dj.findPar(it.second);//finding ultimate parent
        merged[parentNode].push_back(email);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (merged[i].size() == 0)
        {
            continue;
        }
        sort(merged[i].begin(), merged[i].end());
        string name=accounts[i][0];
        merged[i].insert(merged[i].begin(),name);
        ans.push_back(merged[i]);
    }
    return ans;
}