#include <bits/stdc++.h>
using namespace std;

/*
given an array and int a
return a vector of vectors whose some is equivalent of a
the quadruplets should be unique(not similar) and the indexes
of each element in the quadruplet should be unique as well

*/

/*BRUTE
using four for loops and set data stucuture to ensure unique quadruplets
T.C O(n^4 *log(number of unique quadruplets))(sorting is on constant time so not considered)
S.C O(2*unique quadruplets)

T.C may be O(n^4) only (striver)
*/

vector<vector<int>> brute(vector<int> v, int a)
{
    int n = v.size();
    set<vector<int>> st; // a set whci stores inique triplets
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = v[i] + v[j];
                    sum = sum + v[k]; // doing this to handle very large sums(helps)
                    sum = sum + v[l];
                    if (sum == a)
                    {

                        vector<int> temp = {v[i], v[j], v[k], v[l]}; // temporary qudruplet
                        sort(temp.begin(), temp.end());              // sorting to store unique triplets
                        st.insert(temp);                             // set to make sure only uniques are triplets stored
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); // stores whole set in vector
    //(converting set to vector)
    return ans;
}

/*BETTER
using hashset and findind an element
just like in threesum

T.C O(n^3*log m)
S.C O(N)+O(2*number of unique quadruplets)
*/

vector<vector<int>> better(vector<int> v, int a)
{
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashset;

            for (int k = j + 1; k < n; k++)
            {
                long long sum_of_3 = v[i] + v[j];
                sum_of_3 = sum_of_3 + v[k]; // DOING THIS TO HANDLE VERY LARGE NUM
                long long rem = a - (sum_of_3);
                if (hashset.find(rem) != hashset.end())
                {
                    vector<int> temp = {v[i], v[j], v[k], (int)rem}; // temporary qudruplet
                    sort(temp.begin(), temp.end());                  // sorting to store unique triplets
                    st.insert(temp);
                }
                hashset.insert(v[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*OPTIMAL
we use 4 pointer and 3 loop on a sorted array
same approach as in 3 sum
T.C nearly about O(n^3)
S.C O(number of quadruplets) (to return)
*/

vector<vector<int>> optimal(vector<int> v, int a)
{
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
         if(i>0&&v[i]==v[i-1]){continue;}

        for (int j = i + 1; j < n; j++)
        {
            if(j>i+1&&v[j]==v[j-1]){continue;}
            int k = j + 1;
            int l = n - 1;
            while (l > k)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if (sum > a)
                {
                    l--;
                }
                else if (sum < a)
                {
                    k++;
                }
                else // sum==0
                {
                    vector<int> temp = {v[i], v[j], v[k], v[l]};

                    ans.push_back(temp);
                    k++;
                    l--;
                    while(l>k&&v[k-1]==v[k]){ k++; }
                    while(l>k&&v[l+1]==v[l]){ l--; }
                }

            }
        }
    }
}
