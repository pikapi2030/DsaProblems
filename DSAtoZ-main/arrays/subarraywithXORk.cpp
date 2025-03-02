#include <bits/stdc++.h>
using namespace std;

/*
given a array and int k find total number of sub arrays wtih XOR=k
*/

/*BRUTE
using three loops, genrate all sub arrays and their xor
T.C O(n^3)

S.C O(1)
*/
int BRUTE(vector<int> v, int k)
{
    int cnt = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int XOR = 0;
            for (int l = i; l <= j; l++)
            {
                XOR = XOR ^ v[l];
            }
            if (XOR == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

/*BETTER
using two for loops, calculating xor without using extra loop
T.C O(n^2)
S.C O(1)
*/

int BETTER(vector<int> v, int k)
{
    int n = v.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int XOR = 0;
        for (int j = i; j < n; j++)
        {
            XOR = XOR ^ v[j];
            if (XOR == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

/*OPTIMAL

we use prefix xor technique(same as in subarray sums)
we take a cnt variable

NOTE:  if a^b=c  the  a=b^c (xor b both sides)(we will use this)

we will maintain a xori (xor till i) var and a hashmap, key as xori,value as freq of xori
let remxor =xori^k
we know that k=remxor^xori therefore k exists if such remxor exists
and k exists that many times , as many times remxor exists so we will simply add 
frequency of remxor to our cnt which is stored in our map like:map[remxor]=frequency of remxor
map[remxor]=frequency of remxor

therefore cnt=cnt+map[remxor];  if remxor is not there, frequency will be anyway zero(due to map)

T.C O(n*logn)
S.C O(n)


*/

int optimal(vector<int> v, int k)
{
    int n = v.size();
    map<int, int> mp;
    mp[0] = 1;    // to handle xori==k
    int xori = 0; // xor till i
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        xori = xori ^ v[i];
        int remxor = xori ^ k;
        cnt = cnt + mp[remxor];//adding freq of remxor,if remxor not found it is already zero
        mp[xori] = mp[xori]+1;//adding xori to hashmap with freq 1
    }
    return cnt;
}
