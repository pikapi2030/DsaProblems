#include <bits/stdc++.h>
using namespace std;
/*
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).

For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings
"aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in
lexicographical order.

Return the kth string of this list or return an empty string if there are less than k
happy strings of length n.



Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1.
The third string is "c".

Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3
["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"].
You will find the 9th string = "cab"

*/

/*Brute aproach(back track) T.C O(n*2^n)
generate all sequences of length n in a lexographical order, then return the kth index
*/

void gen(string &curr, int n, vector<char> &usables, vector<string> &setOfHappy)

{
    if (curr.size() == n)
    {
        setOfHappy.push_back(curr);
        return;
    }
    for (int i = 0; i <= 2; i++) // travesing usables, which are in lexographical order
    {
        if (curr.empty())
        {
            curr.push_back(usables[i]);
            gen(curr, n, usables, setOfHappy);
            curr.pop_back();
        }
        else if (curr.back() != usables[i])
        {
            curr.push_back(usables[i]);
            gen(curr, n, usables, setOfHappy);
            curr.pop_back();
        }
    }
}

string BRUTE(int n, int k)
{

    string current;
    vector<string> setOfHappy;
    vector<char> usable = {'a', 'b', 'c'};
    gen(current, n, usable, setOfHappy);
    if (k > setOfHappy.size())
    {
        return "";
    }

    return setOfHappy[k - 1];
}

/*Optimal using math, T.C O(N), S.C O(1)
total number of possible happy string of lenght n are 3*2^(n-1) //by pemutation (3ways*2ways*2ways...n-1 times)
we know these total number of string are divides into 3 parts, depending of starting char
let total string be t, then 1 to t/3 string will have a as first char,
t/3+1 to 2t/3 will have b as first char, 2t/3+1 to t will have c as first char
now these subgroups are further divided into 2 groups, depending on choice of second char

assume we are in first sub groug (a), if we want to go to right side next char will be
c as it is lexographically biggeer then b, so all string on right side of sub group a
will start with ac, and on left side with ab

we can normalise k again and again to generate our happy string
*/
string optimal(int n, int k)
{
    int t = 3 * (1<<(n-1)); // total possible strings, 1<<n-1 means 2^n-1
    if(k>t){return "" ;}
    string ans;
    if (k <= t / 3) // first letter a
    {
        ans.push_back('a');
        // no need to change k
        // change t to find mid of subgroup in the while loop
    }
    else if (1 + t / 3 <= k && k<= (2 * t / 3)) // first letter b
    {
        ans.push_back('b');
        // subtract all a group possile strings
        k = k - t / 3;
    }
    else // first letter c
    {
        ans.push_back('c');
        // subtract all a and b group strings
        k = k - (2 * t / 3);
    }
    t = t / 3; // update total possible strings

    while (ans.size() != n)
    {
        int mid = t / 2;
        char lastChar = ans.back();
        if (k <= mid) // left half, lexographically smaller, no need to update k
        {
            if (lastChar == 'a')
            {
                ans.push_back('b');
                
            }
            else if (lastChar == 'b')
            {
                ans.push_back('a');
            }
            else // last char c
            {
                ans.push_back('a');
            }
        }
        else//right half,lexographically larger
        {
            k=k-mid;// update k as well
            if (lastChar == 'a')
            {
                ans.push_back('c');

            }
            else if (lastChar == 'b')
            {
                ans.push_back('c');
            }
            else // last char c
            {
                ans.push_back('b');
            }
        }
        t=t/2;//update possible strings
    }
    return ans;
}

int main()
{
}
