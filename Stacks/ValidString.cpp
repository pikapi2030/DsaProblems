#include <bits/stdc++.h>
using namespace std;

/*
is string valid?
Leetcode :20
([]{}) is valid
([)] is invalid
) is invalid

*/

/*OPTIMAL
we use a stack to solve this problem
when ever we see a opening braket we store it in a stack,
when ever we see a closing braket we check if the top of stack is equal to opening
braket than our string is valid till now and we pop the opening braket present before

if we encounter a closing braket first before a opening bracket(invalid) then our stack would
we empty and it will return false

if at the end of the loop our stack is not empty that means an opening braket is not closed
so invalid string

//! T.C O(N) 
//! S.C O(N)

*/

bool optimal(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (st.empty())/*if we encounter an closing before opening than it is invalid
        (stack would be empty if that happens)*/
        {
            return false;
        }

        char ch = st.top();//storing top to compare
        if ((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '}'))
        //if top and the closing braket are of similar bracket type then string is not invalid and we pop the top
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    if (st.empty())//if stack is not empty this means an opening braket is not yet closed
    {
        return true;
    }
    return false;
}
