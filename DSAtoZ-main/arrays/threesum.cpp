#include <bits/stdc++.h>
using namespace std;
void printvofv(vector<vector<int>>v)
{
int n=v.size();
for(int i=0;i<n;i++)
{
    int m=v[i].size();
    cout<<" [";
    for(int j=0;j<m;j++)
    {
        cout<<" "<<v[i][j]<<" ";
    }
    cout<<"] ";
}
}

/*
given an array
return all triplets with sum=0, indexe within triplets should be unique
and rarranging a triplet will not be counted as another triplet
*/

/*BRUTE
using 3 for loop for triplets and sorting and set data structure to make sure we store
unique triplets
T.C:O(N^3 *LOG(number of unique triplets)) //log due to insert function(may vary on type of set)
S.C: O(2number of triplets)(one with array(ans array), other with set)
IN T.C sorting is not considered as only sorting 3 elements would take constant time

*/

vector<vector<int>> brute(vector<int> v)
{
    int n = v.size();
    set<vector<int>> st; // a set whci stores inique triplets
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == 0)
                {
                    vector<int> temp = {v[i], v[j], v[k]}; // temporary triplet
                    sort(temp.begin(), temp.end());        // sorting to store unique triplets
                    st.insert(temp);                       // set to make sure only uniques are triplets stored
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); // stores whole set in vector
    //(converting set to vector)
    return ans;
}

/*BETTER
we will use hashing (a hash set)(prefix sum technique) and two for loop
we will calculate v[i]+v[j] using for loop and then search for a third number
-(v[i]+v[j]) in hash set, if that is found our triplet is complete

we will make a new hashset every iteration of i
each i gets it own hashset
to make sure that i,j,k are unique in our triplet our hash set will only
contain elements between i and j and would be updated every iteration of j
(now the quetion is what if the third is not in between i and j, don't wory that third
will also become j after on a particular iteration of j, so previous third is our current j
 so our previous j(when previous third was not between) will become
our curent third ) so it would be added as a triplet this way we take all the favrable
triplets

also make sure to add only unique triplets as done in  brute solution

T.C O(n^2)(Log M)(log(number of unique triplets)) where M variable(log(M) due hashset.insert)
M represents current elements in hashset
other log due to st.insert()
t.c due to sorting is constant time so not considered

S.C
O(N)(due to hashset) +O(2*number of unique triplets)(ans vector and set vector)
*/
vector<vector<int>> threeSum(vector<int> &v)
{
    int n = v.size();
    set<vector<int>> st; // the set which stores unique triplets
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(v[i] + v[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {v[i], v[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(v[j]); // inserting elements between i and j
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*OPTIMAL

we use three pointers and two for loops
we try to make sure that the triplets we get are already unique and are in sorted order
first we will sort the array
now we keep i=0(will remain constant till nexter iteration of outer for loop)
j=i+1 and k at n-1
sum=v[i]+v[j]+v[k]
if sum>0 decrease sum be moving k to left until k comes to element diffrent
than it's previous element

simlarily if sum<0 move j to the right until it gets a element diffrerent than it's previous

if(sum==0) than i,j,k are triplets, now move j to right and k to left until they get and
element different than their previous ones(to make sure we won't get same or similar triplets)

any moment j and k touch or cross end the inner loop and iterate i to right until
it gets and element diff than it's previous(to prevent getting same triplets)

T.C O(nlogn)+O(n^2)
S.C O(n.o of unique triplets)

*/

vector<vector<int>> optimal(vector<int> &v)
{
    sort(v.begin(),v.end());
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue; // if previous and curent element same do another
        // iteration until getting different
        int j = i + 1;
        int k = n - 1;
        while (j<k)
        {
                        cout<<" LOOP ";
            cout<<"i:" <<v[i]<<" j:"<<v[j]<<" K: "<<v[k];

            int sum = v[i] + v[j] + v[k];
            if (sum > 0)
            {
                k--;
                /*
                no need of while lopp here for countinious ++ because if v[k]==v[k-1]
                sum will not change anyway
                */
            }
            else if (sum < 0)
            {
                j++;
            }
            else // sum==0
            {
                vector<int>temp={v[i],v[j],v[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (v[j] == v[j - 1] && j < k) // if j>kthen no point of running loop
                {
                    j++;
                }
                while (v[k] == v[k + 1] && j < k)
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int>v={-2,0,1,1,1,2};
    printvofv(optimal(v));
    
}