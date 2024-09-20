#include <iostream>
using namespace std;
// Implementing a stack(LIFO) using arrays

class stack
{
public:
    int top = -1;
    int st[100]; // 100 is max size of stack

    //! ALL FUNCTIONS BELOW HAVE O(1) T.C and O(100) S.C(array of 100)
    // push function(inserts)
    void push(int x)
    {
        if (top >= 100)
        {
            cout << "overflow";
            return;
        }

        top++;
        st[top] = x;
    }
    // pop function(removes)
    void pop()
    {
        if (top == -1)
        {
            cout << "stack empty";
            return;
        }
        top--;
    }
    // top function(return the last element inserted)
    int top()
    {
        if (top == -1)
        {
            cout << "stack empty";
            exit(0);
        }
        return st[top];
    }

    int size() // return size of stack(total elements in stack)
    {
        return top + 1;
    }
};