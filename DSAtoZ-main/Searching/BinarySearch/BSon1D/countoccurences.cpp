#include <bits/stdc++.h>
using namespace std;

/*
given an array and a num, return how many times the number comes in an array

try doing it in O(logN)
*/
// loop aproach will take O(N)

/*BS aproach
we will calculate lower bound and upper bound and subtracting them will give me count of
the num
*/
int OPTIcounter(vector<int> v, int num)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int lp = v.size(), up = v.size();

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (v[mid] >= num)
        {   
            lp = mid;
            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }
    low = 0;
    high = n - 1;
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (v[mid] > num)
        {
            up = mid;
            high = mid - 1;
        }
        else
        {  
            low = mid + 1;
        }
    }

    return up - lp;
}
int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 3, 3};
    cout<<OPTIcounter(v, 3);
    
}
