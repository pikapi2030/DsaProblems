#include <iostream>
#include <vector>
using namespace std;

/*Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

*/

/*Aproach
we can calculate the amount of rain water trapped by calculation R.water on top
of each building and summing it up, to calculate R.w on each bulding i we can calulate
left max of i and right max of i, then //!R.w=min(leftmax,right max)-arr[i](arr[i] represents
bulding height)
we need ways to calculate this left max and right max
*/

/*Brute
we calculate left max and right max using prefix and suffix arrays,
prefix[i] is max of H[i] and prefix[i-1], so it is max of prexfix[0],prefix[1]
till prefix[i](max of prefix[i-1]and prefix[i] is also max of prefix[i-2],prefix[i-1] and
prefix[i])
similarly a suffix[i] array
*/

vector<int> Prefix(vector<int> H)
{
    int n = H.size();
    vector<int> Prefix(n);
    Prefix[0] = H[0];
    for (int i = 1; i < n; i++)
    {
        Prefix[i] = max(H[i], Prefix[i - 1]);
    }
    return Prefix;
}

vector<int> Suffix(vector<int> H)
{
    int n = H.size();
    vector<int> Suffix(n);
    Suffix[n - 1] = H[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        Suffix[i] = max(H[i], Suffix[i + 1]);
    }
    return Suffix;
}




    int trap(vector<int>& H) 
    {
        int n = H.size();
    if(n==0||n==1)
    {
        return 0;
    }
    int Rainsum = 0;
    vector<int> SUF = Suffix(H);
    vector<int> PRE = Prefix(H);
    for (int i = 0; i < n; i++)
    {
        int leftmax = PRE[i];
        int rightmax = SUF[i];

        if (H[i] < leftmax && H[i] < rightmax)
        {
            Rainsum = Rainsum + (min(leftmax, rightmax) - H[i]);
        }
    }
    return Rainsum;
    
    }
