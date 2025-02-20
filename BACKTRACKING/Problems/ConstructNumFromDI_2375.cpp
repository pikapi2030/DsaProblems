#include <bits/stdc++.h>
using namespace std;
/*
You are given a 0-indexed string pattern of length n consisting of the characters 'I'
meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

    num consists of the digits '1' to '9', where each digit is used at most once.
    If pattern[i] == 'I', then num[i] < num[i + 1].
    If pattern[i] == 'D', then num[i] > num[i + 1].

Return the lexicographically smallest possible string num that meets the conditions.



Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.

Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.

*/

/*BRUTE APROACH   T.C O(n*n!)
we will start from lowest string possible(lexographical order) an check if it saitsfies the
condition, if not we will generate next permutation,
we will do this till we a a string which satisfies our condition
*/
bool isSatisfied(string pattern, string num) // to check if num satisfies the given pattern
{
    int n = num.size();
    for (int i = 0; i < n; i++)
    {
        if (pattern[i] == 'I')
        {
            if (num[i] > num[i + 1])
            {
                return false;
            }
        }
        if (pattern[i] == 'D')
        {
            if (num[i] < num[i + 1])
            {
                return false;
            }
        }
    }
    return true;
}

void nextPerm(string &s) // to generate next pemutation
{
    // find breaking point
    int n = s.size();
    int breakpt = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] < s[i + 1])
        {
            breakpt = i;
            break;
        }
    }

    if (breakpt == -1)
    {
        reverse(s.begin(), s.end());
        return;
    }
    // find num just greater than s[breaking] in breaking point+1 and n
    for (int i = n - 1; i > breakpt; i--)
    {
        if (s[i] > s[breakpt])
        {
            swap(s[i], s[breakpt]);

            break;
        }
    }
    reverse(s.begin() + breakpt + 1, s.end());
}

string BRUTE(string pattern)
{
    string ans;
    // generated smallest(lexographically) possible answer
    for (int i = 0; i <= pattern.size(); i++)
    {
        ans.push_back(i + 1 + '0');
    }
    while (!isSatisfied(pattern, ans))
    {

        nextPerm(ans);
    }
    return ans;
}

/*Optimal Aproach using stack
we will keep a counter which keeps increasing when we traverse our pattern,
if we see a D, we increase the counter and push it in our stack,
if we see and I we increase the counter, push it in out ans, then empty the stack
by pushing all the elements in our answer string
when we reach end on the pattern, //!!we will push the last cnt in our stack(as size of ans is 1+size of pattern)
then we again empty the stack to push remaining elemnts in ans string
in our ans string
*/

string optimal(string pattern)
{
    int cnt = 1;
    stack<int> st;
    string ans;
    for (int i = 0; i < pattern.size(); i++)
    {
        
        if (pattern[i] == 'I')
        {
            st.push(cnt);
            
            while (!st.empty())
            {
                ans.push_back(st.top()+'0');
                st.pop();
            }
        }
        else if(pattern[i]=='D')
        {
            
            st.push(cnt);
        }
        cnt++;
    }
      st.push(cnt);//last push as ans.size()=pattern.size()+1  

    while(!st.empty())
    {
        ans.push_back(st.top()+'0');
        st.pop();
    }
    return ans;
}
