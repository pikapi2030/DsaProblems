#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
    queue<pair<string,int>>qs; 
     qs.push({beginWord,0});
     int ans=1e5;
     set<string>st(wordList.begin(),wordList.end());
     st.erase( beginWord );
     while(!qs.empty())
     {
        string curWord=qs.front().first;
        int level=qs.front().second;
        qs.pop();
        if( curWord==endWord )
        {
            ans=level;
            return ans;
        }
        for(int i=0;i<curWord.size();i++)
        {
            char orignal=curWord[i];
            for(char j='a';j<='z';j++)
            {
                
             curWord[i]=j;
            if(  st.find(curWord)!=st.end() )
            {
                qs.push({ curWord,level+1 });
                st.erase( curWord ); 
            } 
            }
            curWord[i]=orignal;
        }

     }
     return 0;



    }
};