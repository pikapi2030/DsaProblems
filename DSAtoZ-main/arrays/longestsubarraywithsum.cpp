#include <bits/stdc++.h>
using namespace std;
/*
array contains positives
find the longest sub array with sum equal to k(given)
*/

/*
brute force solution
generate all the subarrays, find sum and length
and find max length

to generate subaarays
i=0 to i=0 is a sub array        i=1 to i=1  ........  i=n-2 to i=n-1 is sub array i=n-1 to i=n-1 is a subarray
i=0 to i=1                       i=1 to i=2                                   .
i=0 to i=2                                .
i=0      .                                .
         .                                .
         .                                .
         .                                .
         .                                .
i=0 to i=n-1 is a sub array      i=1 to  i=n-1 is sub array

T.C O(n*n*n)
S.C O(1)

*/

/*
brute force 2
when we move j, just add the new element in our sum
instead using another loop to calculate sum
T.C O(n^2)
S.C  O(1)
*/

int lsbrute1(vector<int> v, int k)
{
    int length = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int l = i; l <= j; l++)
            {
                sum = sum + v[l];
            }
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

int lsbrute2(vector<int> v, int k)
{
    int length = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + v[j];
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

/*
better solution
we iterate with i
we  mantain a  map of sum till i ,  i
and we maintain a sum till i as well
now to find sub array with desired sum
we check if (sum till i)-k is available on our map
if it is then our length of sub array is i+1 of map till i
watch vid for better undestanding

T.C O(n*logn)(if ordered maps is used) or O(n*1)(if unordered map best/average case) or
O(n*n)(ordered map worst case)
*/
// THE FUNC BELOW IS THE MOST OPTIMAL FOR SAME QUETION IF ARRAY ALSO CONTAINS NEGATIVES
int lsbetter(vector<int> v, int k)
{
    map<int, int> mp;
    int n = v.size();
    int maxl = 0;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {

        presum = presum + v[i];
        if (mp.find(presum) == mp.end()) 
/*
this lines means, if there is already same key(presum) present
 this is done to handle zeroes
 zeroes will not change presum and we wan't
 longest length of i should be min on same presums
which is when first presum occured
ex-a[]={2,0,0,3} k=3
map will be like
(2,2)(5,3) without the condition as (2,0) and (2,1) got updated
 so maxl would be 1 but maxl is 3
  only possible when (2,0) is not updated
watch
 by adding this also works for negative and is the most optimal          
 */

            mp[presum] = i;
        if (presum == k)
        {
            maxl = max(maxl, i + 1);
        }
        int rem = presum - k;
        if (mp.find(rem) != mp.end()) // the find function retuens end if key no found,
              // so no end returned means key fou0nd
            
        {
            maxl = max(maxl, i - mp[rem]);
        }
    }
    return maxl;
}

/*
only for positives and zero
in optimal approach we use tow pointers
one pointer moves if sum of current sub array is less than k
when sum==k we check lenght and when sum>k the other pointer moves to trim
rhe sub array
*/

int lsopti(vector<int> v, int k)
{
    int n = v.size();
    int i = 0, j = 0; // i moves when sum<k k moves when sum>k
    int sum = v[0];
    int length = 0;
    while (i < n)
    {
        while (sum > k && j <= i)
        {
            sum = sum - v[j];
            j++;
        }
        if (sum == k)
        {
            length = max(length, i - j + 1);
        }
        i++;
        if (i < n)
        {
            sum = sum + v[i];
        }
    }
    return length;
}
