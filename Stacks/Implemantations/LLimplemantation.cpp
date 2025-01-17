#include <iostream>
using namespace std;
//! implementing stack using ll makes space dynamic instead of static in case of arrays
class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        data = a;
    }
};

class stack
{
public:
    Node *top = NULL;
    int size = 0;

    // Methods
    //! T.C O(1) S.C O(required space)(dynamic)
    // Push

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    // pop
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack is empty";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // top

    int TOP()
    {
        if (top == NULL)
        {
            cout << "empty stack";
            return;
        }
        return top->data;
    }

    // size

    int size()
    {
        return size;
    }
};