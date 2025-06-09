#include <bits/stdc++.h>
using namespace std;
/*
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in
wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is
a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is
trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list
of words.
Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
*/

/*aproach
it is similar to LIS, instead of checking for if it is increasing, we check if the difference
between the strings is of one character
//!sorting by length is imp, as we consider our next string must be larger than previous,
all we are doing is checking if it also differs by one char
*/

static bool comp(string &a,string &b)
{
    return a.size()<b.size();
}

bool isOneCharDiff(string &a, string &b) // a is smaller string, b is larger string
{
    if (a.length() + 1 != b.length())
    {
        return false;
    }
    int ai = 0, bj = 0;
    while (bj < b.size())
    {
        if (ai < a.size() && a[ai] == b[bj])
        {
            ai++;
        }

        bj++;
    }
    return ai==a.size();
}

int Tab1D(vector<string> &v)
{
    sort(v.begin(),v.end(),comp);
    int n = v.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int pi = 0; pi < i; pi++)
        {

            if (isOneCharDiff(v[pi], v[i]))
            {
                dp[i] = max(dp[i], dp[pi] + 1);
            }
        }

        ans = max(dp[i], ans); // tell max from dp[i]
    }
    return ans;
}
