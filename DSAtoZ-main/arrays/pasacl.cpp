#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
}

/*problem 1
given a row number nd a column number return the number present in pascal triangle
at those coordinates(startinf from 1)
*/

/*
if a is row num,b is column num than combination of a-1 and b-1 gives the required ans
combination means N^c_r (prermutation and combination vala)

to calculate combination efficietly we use a trick
instead of N^c_r = N!/((N-r)!*r!) we reduce N and r, r times and put N in numrator and
r in denominator(multiplying)

example 7^c_3= (7*6*5)/3*2*1

*/
int combination(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
    // T.C O(r)
    // S.C O(1)
}

int pascal(int row, int column)
{
    return combination(row - 1, column - 1);
}

/*problem 2
given row number(starting from 1) of pascal triangle, return the whole row
*/

/*BRUTE problem 2
R.C O(n*r)
we simply use ncr trick
*/

vector<int> rowbrute(int n)
{
    vector<int> ans;
    for (int c = 1; c <= n; c++)
    {
        ans.push_back(combination(n - 1, c - 1));
    }
    return ans;
}
/*OPTIMAL PROBLEM 2
better solution we try to calculate the pascal low
element with help of previous elment by finding a pattern
a =1;
a=a*(n-colm)/colm
ans.push_back(ans);
T.C O(n)
S.C O(1)
*/

vector<int> rowbetter(int n)
{
    vector<int> resutl;
    int ans = 1;
    resutl.push_back(1);
    for (int c = 1; c < n; c++)
    {
        ans = ans * (n - c);
        ans = ans / c;
        resutl.push_back(ans);
    }
    return resutl;
}

/*problem 3
return a vector of vectors consisting of pascal triangle till row n
*/

/*BRUTE problem 3
we use two for loops, iterating through every elment of pascal triangle and
pushing it back by combination function
if we know row and clmn of element we can get that element by using combination function
T.C O(n*n*r) nerarly order of O(n^3)
*/

vector<vector<int>> PASCALTRIANGLEbrute(int n)
{

    vector<vector<int>> result;
    for (int row = 1; row <= n; row++)
    {
        vector<int> temp;

        for (int c = 1; c <= row; c++)
        {
            temp.push_back(combination(row - 1, c - 1)); // adds element of row
        }
        result.push_back(temp); // adds whole row
    }
    return result;
}

/*
in optimal solution we will just genrate rows in
loops using rowbetter function

T.C is near about O(n*n)
*/
vector<vector<int>> PASCALTRIANGLEopti(int n)
{
    vector<vector<int>> result;
    for (int i = 1; i <= n; i++)
    {
        result.push_back(rowbetter(i));
    }
    return result;
}

int main()
{
    printv(rowbetter(2));
}
