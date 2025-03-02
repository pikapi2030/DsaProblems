#include<bits/stdc++.h>
using namespace std;
/*
given a n*m matrix return true if target present else false

catch: the array is sorted row and column wise, BUT THE  MATRIX AS A WHOLE IS NOT SORTED
like a and ith row can have larger numbers than rows ahead 

*/

/*BRUTE
travesal whole of martrix to search
T.C O(n*m)
*/

/*BETTER
using BS, doing BS on every row if target found return true
(we have to do it in every row becuse matrix as a whole is not sorted)
T.C O(N*log_2 M)
*/

bool BinarySearch(vector<int> v, int target)
{
    long long low = 0, high = v.size() - 1;
    while (high >= low)
    {
        long long mid = (high + low) / 2;
        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
    
}

bool BETTER(vector<vector<int>> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (target >= v[i][0] && target <= v[i][v[0].size() - 1]) // there is possibility of target in this row
        {
            if( BinarySearch(v[i], target))
            {
                return true;
            }
        }
    }
    return false; 
}


/*OPTIMAL
this solution is very clever

what we do is we start from top right corner of matrix(we can also start from bottom left)
first we check if the element we are on is equal to target or not

lets take an example, our target is 14

0th 1st 2nd 3rd 4th row

1   4   7    11  15<-- we are here initialy
2   5   8    12  19
3   6   9    16  22
10  13  14   17  24
18  21  23   26  30

since 15!=14, and 15>14 so 14 cannot be in column 4, so we do a column--;
after that we are on 11, now our 0th row cannot have 14(largest is 11) 
so we do a row++
now we are on 12, since 14>12, we do a row++
and so on untill we reach 14

so basically when v[row][column]>target do a colum--
else do a row++

T.C O(n+m) when our target is on the opposite corner 


*/

bool OPTIMAL (vector<vector<int>>v,int target)
{
    long long row=0,column=v[0].size()-1;
    while(v.size()>row&&v[0].size()>column)
    {
     if(v[row][column]==target)
     {
        return target;
     }
     else if(v[row][column]>target)
     {
        column--;
     }
     else//v[row][column]<target
     {
        row++;
     }
    }
    return false;

}

