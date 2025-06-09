#include <bits/stdc++.h>
using namespace std;
/*
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then 
strictly decreasing.
A strictly ascending order sequence is also considered bitonic, with the decreasing part 
as empty, and same for a strictly descending order sequence.
For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, 
whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.
You are given an array 'arr' consisting of 'n' positive integers.
Find the length of the longest bitonic subsequence of 'arr'.
Example :
Input: 'arr' = [1, 2, 1, 2, 1]
Output: 3
Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. 
Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive
2's are neither strictly increasing, nor strictly decreasing.
*/

/*aproach
we generate two dp arrays dp1 and dp2
dp1[i]= LIS till index i in array v
//!dp2[i]=LIs till index i, in array reverse(v)=longest decreasing subsequence from n-i-1 to n
longest Biotonic= max(dp1[i]+dp2[i]-1,dp1[i],dp2[i]) for an i
*/

int Tab1D(vector<int> &v)
{
    int n = v.size();
    vector<int> dp1(n, 1);
    vector<int>dp2(n,1);
    for (int i = 0; i < n; i++)
    {
        for (int pi = 0; pi < i; pi++)
        {
            int revi=n-i-1;
            int revPi=n-pi-1;

            if (v[i] > v[pi])
            {
             dp1[i]=max(dp1[i],dp1[pi]+1);
            }
            if( v[revi]>v[revPi] )
            {
                dp2[revi]=max(dp2[revi],dp2[revPi]+1);
            }
        }
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans=max({ans,dp1[i]+dp2[i]-1,dp1[i],dp2[i]});//without dp1 or dp2 check also works fine
    }
    return ans;
    
}

