#include <bits/stdc++.h>
using namespace std;
/* given two sorted array V1 and V2, find number of inversions(pairs) with V1[i]>2*V2[j]
and i>j
similar quetion to inversion between arrays but instead of v1[i]>v2[j] we check for
v1[i]>2*v2[j] and i>j

we can use the same aproach as used in inversion b/w array but we will a slightly different
one which will help us to solve countinversionscondition493


*/

/*OPTIMAL

keeping i on left array and j on right array,
if V1[i]>V2[j] till lets say x(index in V2), then for next V1[i]
it is guranteed it wiil have pairs till x (both sorted) so we will start our j pointer
from x+1 and not from the start

*/

int opti(vector<int> v1, vector<int> v2)
{
    int n = v1.size();
    int m = v2.size();
    int cnt = 0, j = 0;
    for (int i = 0; i < n; i++)
    {

        while (v1[i]>2*v2[j])
        {
            if (j < m)
            {
                j++;
            }
        }
        cnt = cnt + (j);//ading amount of j moved
    }
    return cnt;
}

int main()
{
    vector<int>v1={12,15,18,23,25};
    vector<int>v2={6,8,9,11,13};
    cout<<opti(v1,v2);
}