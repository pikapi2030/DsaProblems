#include <iostream>
#include <vector>
using namespace std;
/*
find maximum number of consecutive 1 in an array with only 1 and 0
a[]={1,1,1,0,1,0,0,1,1,0,1}
output=3
*/

/*
approach
we iterate through array and keep a conter and a max
as soon as we see a 1 we increase the counter
as soon as we see zero we se counter to zero while storing its value in max
update max if max is found

T.C O(N)
S.C O(1)
*/
int cons(vector<int> v)
{
    int n = v.size();

    int cnt = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            cnt++;
        }

        if (v[i] == 0  ||i == n - 1)
        {
            if (cnt > max)
            {
                max = cnt;
            }
            cnt = 0;
        }
    }
    return max;
}

int main()
{
    vector<int> v = {1, 1};
    cout<<cons(v);
}