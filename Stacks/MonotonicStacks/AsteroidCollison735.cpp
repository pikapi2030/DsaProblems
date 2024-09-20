#include <bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.


    [1,-2,10,-5]
    here, 1 and -2 will collide and 10 and -5 will collide but -2 and 10 wont collide.
    result -> [-2, 10]
    [-4, 6]
    here, -4 will move left and 6 to its right and will never collide
    result -> [-4, 6]
    but in
    [4, -6] 4 and -6 will collide and stronger asteroids will remain, as 6 is stronger than 4 , so -6 will remain resulting [-6].


*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Mysol(vector<int> v)
{
    stack<int> st;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top() < 0 || v[i] > 0)
        {
            // No collision possible, just push the current asteroid
            st.push(v[i]);
        }
        else
        {
            // Collision possible (st.top() > 0 and v[i] < 0)
            bool destroyed = false; // Flag to check if the current asteroid is destroyed

            while (!st.empty() && st.top() > 0 && !destroyed)
            {
                if (abs(v[i]) == st.top())
                {
                    // Both asteroids are of equal size, destroy both
                    st.pop();
                    destroyed = true;
                }
                else if (abs(v[i]) > st.top())
                {
                    // The incoming asteroid destroys the one at the top
                    st.pop();
                }
                else
                {
                    // The asteroid at the top survives, and the current one is destroyed
                    destroyed = true;
                }
            }

            // If the current asteroid was not destroyed, push it to the stack
            if (!destroyed)
            {
                st.push(v[i]);
            }
        }
    }

    // Extract the result from the stack
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end()); // Reverse the result to get the correct order
    return ans;
}
