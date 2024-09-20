#include <iostream>
using namespace std;

/*all queue are assumed to be circular
(if current size is less than total but start is at end of array it will go to 0th index)
*/


class qeue
{
    int start, end = -1;
    int currentsize = 0;
    int MaxSize = 100; // assuming 100
    int q[100];
    // Methods
//! all functions of T.C O(N), S.C O(MaxSize )
    // push

    void push(int x)
    {
        if (currentsize > MaxSize)
        {
            cout << "qeue FULL";
            return;
        }
        if (currentsize == 0)
        {
            start = 0, end = 0;
        }
        else
        {
            end = ((end + 1) % MaxSize);
        }
        q[end] = x;
        currentsize++;
    }

    // pop
    void pop()
    {
        if (currentsize == 0)
        {
            cout << "Qeue is empty";
            return;
        }
        if (currentsize == 1) // set end,start at-1
        {
            end = start = -1;
            return; 
        }
        start = ((start + 1) % MaxSize);
        currentsize--;
    }
    int top()
    {
        if (currentsize == 0)
        {
            cout << "Qeue is empty";
        }
        return q[start];
    }
    int size()
    {
        return currentsize;
    }
};



