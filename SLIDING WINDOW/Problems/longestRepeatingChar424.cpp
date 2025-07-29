#include <bits/stdc++.h>
using namespace std;
/*
You are given a string s and an integer k. You can choose any character of the string and
change it to any other uppercase English character. You can perform this operation at most k
times.
Return the length of the longest substring containing the same letter you can get after
performing the above operations.
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

/*sliding window(brute sliding window)  T.C O(N+26N)  S.C O(26)
we need to keep a window where  replacement needed is atmost k,
Replacement=  (length-maxFreq) where maxFreq is the freq of the character which occurs
maximum of the times in our window
*/
int bruteSl(string s, int k)
{
    int n = s.size();
    int left = 0, right = 0;
    vector<int> hash(26, 0);
    int maxFreq = 0;
    int Replacemets = 0;
    int ans = 0;

    while (right < n)
    {
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        Replacemets = (right - left + 1) - maxFreq;
        while (Replacemets > k)
        {
            hash[s[left] - 'A']--;
            left++;
            for (int it : hash)
            {
                maxFreq = max(maxFreq, it); // update max freq
            }
            Replacemets = (right - left + 1) - maxFreq; // update Replacements
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

/*better (sliding window) T.C O(2*N)  S.C O(26)
we try to remove that O(26N+N)
//!we can actullay remove the the innermost for loop which reupdates our frequency
we do not need to decrease maxFreq, but to increase it
because when we decrease maxFreq, it will never contribute in our ans so it will
not change it thus preventing us from getting wrong answers,
it will only contribute in our ans when maxFreq increases
*/

int betterSl(string s, int k)
{
    int n = s.size();
    int left = 0, right = 0;
    vector<int> hash(26, 0);
    int maxFreq = 0;
    int Replacemets = 0;
    int ans = 0;

    while (right < n)
    {
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        Replacemets = (right - left + 1) - maxFreq;
        while (Replacemets > k)
        {
            hash[s[left] - 'A']--;
            left++;

            Replacemets = (right - left + 1) - maxFreq; // update Replacements
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int optimalSl(string s, int k)//just replace inner while loop with if block,T.C O(N) S.C O(1)
{
    int n = s.size();
    int left = 0, right = 0;
    vector<int> hash(26, 0);
    int maxFreq = 0;
    int Replacemets = 0;
    int ans = 0;

    while (right < n)
    {
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        Replacemets = (right - left + 1) - maxFreq;
        if (Replacemets > k)
        {
            hash[s[left] - 'A']--;
            left++;

            Replacemets = (right - left + 1) - maxFreq; // update Replacements
        }
        if (Replacemets <= k)
        {
            ans = max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
}
