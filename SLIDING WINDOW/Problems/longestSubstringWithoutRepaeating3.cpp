#include <bits/stdc++.h>
using namespace std;
/*
Given a string s, find the length of the longest
without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

// approach 1:- generate all substrings, keep a hash array to track reoccuring characters
// t.c O(N^2)  s.c O(256)
int Brute(string s)
{
    int maxLenght = 0;
    for (int i = 0; i < s.length(); i++)
    {

        vector<int> hash(256, 0);

        for (int j = i; j < s.length(); j++)
        {

            if (hash[s[j]] == 1) // present already
            {
                break;
            }
            else
            {
                maxLenght = max(maxLenght, j - i + 1);
                hash[s[j]] = 1;
            }
        }
    }
    return maxLenght;
}
// optimal
/*use sliding window, keep an hash array which stores index of occurence of the
characters, if any characters index is greater than left, and it came again
move left to that index+1
*/

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxlen = 0;
    int left = 0, right = 0;
    vector<int> hash(256, -1); // we store index of character found in place of -1
    while (n > right)
    {
        if (hash[s[right]] != -1 && hash[s[right]] >= left) // the duplicate is present in our current window
        {
            left = hash[s[right]] + 1;
        }
        maxlen = max(maxlen, right - left + 1);
        hash[s[right]] = right;
        right++;
    }
    return maxlen;
}
