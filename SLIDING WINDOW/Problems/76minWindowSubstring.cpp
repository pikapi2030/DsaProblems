#include <bits/stdc++.h>
using namespace std;
/*
Given two strings s and t of lengths m and n respectively, return the minimum window
of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

    string minWindow(string s, string t)
    {
        int validityCounter = t.size();
        unordered_map<char, int> mp;
        for (char c : t)
            mp[c]++;

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int ansStart = -1;

        while (right < s.size())
        {
            mp[s[right]]--;
            if (mp[s[right]] >= 0)
                validityCounter--;

            while (validityCounter == 0)
            {
                if (minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    ansStart = left;
                }

                mp[s[left]]++;
                if (mp[s[left]] > 0)
                    validityCounter++;

                left++;
            }

            right++;
        }

        return (ansStart == -1) ? "" : s.substr(ansStart, minLen);
    }

