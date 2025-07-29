#include <bits/stdc++.h>
using namespace std;
/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters
a, b and c.
*/

/*sliding WIndow
we will ke a hash array of size three which stores the last seen index of a,b and c
then we will traverse the array, if last see of a,b,c is not -1 we can see
we have found a valid window with all a,b, and c in it
simply add all the other substrings to the left of the valid window in cnt as well
*/

int numberOfSubstrings(string s)
{
    int n = s.size();
    vector<int> lastSeen(3, -1);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        lastSeen[s[i] - 'a'] = i;
        int mins = min({lastSeen[0],lastSeen[1],lastSeen[2]});

        if (mins != -1)
        {
            ans += mins + 1;
        }
    }
    return ans;
}
