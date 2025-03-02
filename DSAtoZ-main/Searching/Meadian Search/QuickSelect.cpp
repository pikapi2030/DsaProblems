#include <bits/stdc++.h>
using namespace std;
//TODO CORRECT THE CODE DUMBASS
/*
this algorithm is used to find kth smallest element in an unsoted array in lenear T.C
*/

int Qs(int v[], int low, int high, int k)
{
    int size = high - low + 1;
    int RandomIndex = low+rand() % (size); // gives random values from 0 to size
    int pivot = v[RandomIndex];
    int SmallerThanPivot[100];
    int EqualToPivot[100];
    int BiggerThanPivot[100];
    int SmallCnt = 0, EqualCnt = 0, BigCnt = 0;

    for (int i = low; i <= high; i++)
    {
        if (v[i] > pivot)
        {
            BiggerThanPivot[BigCnt] = v[i];
            BigCnt++;
        }
        else if (v[i] < pivot)
        {
            SmallerThanPivot[SmallCnt] = v[i];
            SmallCnt++;
        }
        else
        {
            EqualToPivot[EqualCnt] = v[i];
        }
    }

    if (SmallCnt > k) // k is in Smaller array
    {
        return Qs(v, low, SmallCnt - 1, k);
    }
    else if (SmallCnt + EqualCnt == k) // k is in pivot array,so pivot itself(this case is usefull when there are duplicate pivots)
    {
        return pivot;
    }

    else if (k > SmallCnt + BigCnt) // k is in bigger array
    {
        return Qs(v, 0, BigCnt - 1, k-(SmallCnt+EqualCnt));
    }
}

int main()
{
    int v[5] = {6, 4, 0,536, 435};
    cout << Qs(v, 0, 5, 3);
}
