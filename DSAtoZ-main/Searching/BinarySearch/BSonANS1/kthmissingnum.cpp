#include<bits/stdc++.h>
using namespace std;
/*
given an array v, find kth missing num
v={2,3,4,7} k=2
missing number are={1,5,6...} there output=5(2nd in the missing num array)

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. 
The 2nd missing positive integer is 6.
 

*/

/*BRUTE
if k<v[0]  then the missing num is equal to k
example, v={5,6,8,9}
k=3  missing array={1,2,3,4,7,...}
3rd num is misarray is 3

if k>v[0] 
then we assume k to be our possible ans and increment our ans by one if ans>v[i]
why? watch vid

T.C O(N)

*/

int BRUTE(vector<int>v,int k)
{
    int n=v.size();
    int ans=k;//we also return k and do k++, using ans to undestand better
    
    for(int i=0;i<n;i++)
    {
                if(v[i]>ans)
        {
            return ans;
        }

        else
        {
            ans++;
        }
    }
    return ans;

}

/*OPTIMAL
we us BS
we don normal BS and eliminate on the basis of how many nums were missed till our mid
since we are trying to get our low and high pointers on numbers which have missing num
between our k(explained later why we want this)
example v={2,3,4,7,11}
now number of missing  till mid can be calulated by  v[mid]-(mid+1)
idealy mid+1 should be present instead of v[mid] if there was no missing number
(1,2,3,4,..) 

now at v[mid]=7, missing num count is 3, at 11 is 6 since our k is
5 we try to get our low and high pointer on 11 and 7.

it can be easily do by calculating number of  missing till mid 
and eliminating left half if(n.o of mis<k) and vice versa

no after BS our high is on 7 and low on 11(low>high is condition for loop END)

since till 7 we have 3 missing, and we need 5th missing, we will simply 
add 2 to seven(v[high]+(k-missing till 7])) to get the 5th missing so 9 is our ans

but we can't rely on v[high] as it can sometimes end outside the bounds of array
for example if v={4,7,9}
and k=3 our low will point at 4 and high would be at v[-1](outside bounds)
which can give run time error

SO we will modify our way of calculating ans
we know ans=v[high]+more , more=k-missing , missing(of high) =v[high]-(high+1)
so putting these values,
ans=v[high]+(k-(v[high-high-1]));
simplifying
ans=k+high+1, and high +1 =low
SO THE ANS =LOW+K

T.C O(log_2 N)
*/

int optimal(vector<int>v,int k)
{
    long long low=0,high=v.size()-1;
    while(high>=low)
    {
        long long mid=(low+high)/2;
        long long num_of_missing=v[mid]-(mid+1);
        if(k>num_of_missing)//eliminate left(we need to aproach k)
        {
          low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return (int)low+k;
}

