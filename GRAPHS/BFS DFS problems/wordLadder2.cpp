#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int wordLen = beginWord.size();
        set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        int level = 0;
        queue<vector<string>> qs;
        vector<string> usedTillevel;
        usedTillevel.push_back(beginWord);
        qs.push({beginWord});
        while (!qs.empty())
        {
            vector<string> curSeq = qs.front();
            qs.pop();
            if (curSeq.size() > level) // new level started, erase(mark visited) previous used words from set
            {
                level++;
                for (auto it : usedTillevel)
                {
                    st.erase(it);
                }
                usedTillevel.clear(); // cleared to store next levels used
            }
            string curWord = curSeq.back();
            for (int i = 0; i < wordLen; i++)
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    string newWord = curWord;
                    newWord[i] = j;
                    if (st.find(newWord) != st.end())
                    {

                        vector<string> newSeq = curSeq;
                        newSeq.push_back(newWord);
                        usedTillevel.push_back(newWord);
                        if (newWord == endWord)
                        {
                            if (ans.size() == 0) // first time we reached endWord, thus minimum number of sequences
                            {
                                ans.push_back(newSeq);
                            }
                            else
                            {
                                if (ans[0].size() == newSeq.size()) // all newSeq size should be equal to first newSeq size, as first Reached newSeq is optimal(BFS property)
                                {
                                    ans.push_back(newSeq);
                                }
                            }
                        }
                        qs.push(newSeq);
                    }
                }
            }
        }
        return ans;
    }
};

