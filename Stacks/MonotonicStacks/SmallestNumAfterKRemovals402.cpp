#include <bits/stdc++.h>
using namespace std;

/*
given a numberical string and a int k, remove k numbers from the string and
return smallest possible value
*/

/*
we will use a monotonic stack, our smallest number will be in stack, and will traverse 
the string, and add it to the stack if it is smaller than the top

after that we will remove any more elements if k is not zero
then we will create a res string which is actually reverse of the ans string
with extra zeroes
we will trim those zeroes and returne the res after reversing it

*/

string OPTIMAL(string s, int k)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {

        while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0'))
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while (k > 0)
    {
        st.pop();
        k--;
    }

    if (st.empty())
    {
        return "0";
    }

    string res = "";
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    /*res is is reversed form, it might have zeroes at the end which need to be removed
    (example: if res is "123000" then actual ans is 000123 which actually is 123 so it is
     important to trim the zeroes )*/

    while (res.size() != 0 && res.back() == '0')
    {
        res.pop_back();
    }
    if (res.size() == 0)
    {
        return "0";
    } // if res is string only of zeroes

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
string s;
cin>>s;

cout<<OPTIMAL(s,1);

}

