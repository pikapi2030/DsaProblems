#include <bits/stdc++.h>
using namespace std;
/*
Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '('
    or an empty string "".

*/

/*Brute Aproach
generate all strings possible string (in place of *) using backtracking
if any of the generated is true, return true
*/

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (st.empty()) // stack is empty on an closing braket, therefore invalid
        {
            return false;
        }
        st.pop();
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

bool gen(string &s, string &genString, string &usable, int n)
{
    if (genString.size() == n)
    {
        return isValid(genString);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            for (int j = 0; j < 3; j++)
            {
                
                genString[i] = usable[j];
                return gen(s, genString, usable, n);
                genString[i] = '*';
            }
            genString.push_back(s[i]);
        }
    }
    cout<<"DUMYY!!!!";
    return true;//dummy return, of no significance
}

bool checkValidString(string s)
{
    int n = s.size();
    string usable = "()\0";
    string genString;
    if (gen(s, genString, usable, n) == true)
    {
        return true;
    }
    return false;
}
