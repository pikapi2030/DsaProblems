#include<bits/stdc++.h>
using namespace std;
/*
given a 2d matrix of n*m order
print it's element in spiral order
or return in a vector
*/

/*
this quetion has only optimal solution
we take four variables left, right,top,bottom
we run 4 loops with help of them countiniously to get spiral printing

T.C O(n*m)
at the end of the day we are going through every element once so T.C
would O(number of elements)
*/

vector<int>spiralprintopti(vector<vector<int>>v)
{
    vector<int>ans;
    int n=v.size();
    int m=v[0].size();
    int top=0,bottom=n-1,left=0,right=m-1;
    
while(bottom>=top&&right>=left)
{
    //first loop goes fro left to right and prints top elements
    for(int i=left;i<=right;i++)
    {
        ans.push_back(v[top][i]);//top is constant
    }
top++;//top is moved toward bottom by one index

//second loop is from top to bottom printing right elements
for(int i=top;i<=bottom;i++)
{
    ans.push_back(v[i][right]);
}
right--;//right comes to one index left and prints bottom elements

//third loop goes from right to left
if(top<=bottom)//this condition is for the edge case if we only have one row
{
for(int i=right;i>=left;i--)
{
    ans.push_back(v[bottom][i]);
}
bottom--;//bottom is moved one index towards top
}

//fourth and last loop goes from bottom to top printing left elements
if(right>=left)//this condition to handle edge case of matrix having only one column
{
for(int i=bottom;i>=top;i--)
{
    ans.push_back(v[i][left]);
}
left++;//left is moved towards right by one index
}

}
return ans;
}
