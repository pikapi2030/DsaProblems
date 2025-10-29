#include <bits/stdc++.h>
using namespace std;

/*
A new alien language uses the English alphabet, but the order of letters is unknown.
You are given a list of words[] from the alien language’s dictionary, where the words are
claimed to be sorted lexicographically according to the language’s rules.
Your task is to determine the correct order of letters in this alien language based on the
given words. If the order is valid, return a string containing the unique letters in
lexicographically increasing order as per the new language's rules. If there are multiple
valid orders, return any one of them.
However, if the given arrangement of words is inconsistent with any possible letter ordering,
return an empty string ("").
A string a is lexicographically smaller than a string b if, at the first position where they
differ, the character in a appears earlier in the alien language than the corresponding
character in b. If all characters in the shorter word match the beginning of the longer word,
the shorter word is considered smaller.

*/

class Solution
{
public:
    vector<int> khans(vector<vector<int>> &adjL)
    {
        int n = adjL.size();
        vector<int> ans;
        vector<int> inDegree(n, 0);
        queue<int> qs;
        for (auto it : adjL)
        {
            for (auto ij : it)
            {
                inDegree[ij]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                qs.push(i);
            }
        }
        while (!qs.empty())
        {
            int node = qs.front();
            qs.pop();
            ans.push_back(node);
            for (auto it : adjL[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    qs.push(it);
                }
            }
        }
        if(ans.size()!=n)
        {
            return {};
        }
        return ans;
    }

    string findOrder(vector<string> &words)
    {
        // Build a directed graph
        map<char, int> mp;
        for (auto it : words)
        {
            for (auto ij : it)
            {
                mp[ij]++;
            }
        }
        int numOfUniqueChars = mp.size();

        vector<vector<int>> adjL(numOfUniqueChars);
        for (int i = 0; i < words.size() - 1; i++)
        {
            if( words[i].size()>words[i+1].size())
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); j++)
            {
                if (words[i][j] != words[i + 1][j])
                {
                    adjL[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                    break;
                }
            }
        }

        // perform topo sort(khan's algo)
        vector<int> intans = khans(adjL);
        if (intans.size()==0)//if a cycle then my khans returns an empty vector
        {
            return "";
        }
        string ans = "";
        for (int i = 0; i < intans.size(); i++)
        {
            ans.push_back('a' + intans[i]);
        }
        return ans;
    }
};
