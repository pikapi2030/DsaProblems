#include <bits/stdc++.h>
using namespace std;
/*What is NODE?
Node is a custom defined data type
we have to implement linked list using class

a Node is custom defined data type(implemented via class)
which stores value and address of the next Node
if no next Node is present, it stores null as a address


*/

class Node
{
public:
    int data;
    Node *next; // stores address of the next Node, so is of Node* data type(JESE INT KE ADDRESS KO STORE KARANE KE LIYE INT * CHAIYE)

    Node(int data1)
    {
        data = data1;
        next = NULL; // newly formed nodes do not have any Node next to them so they store NULL
    }
};

/*conversion of array to ll

TO CONVERT An ARRAY TO LL:-
we use three pointers of data type Node to implement LL in array

the value stored by Node is "data", the address is stored by Node is "next"( var name )

nodes are formed using new operator and parametrised constructor
newly formed nodes always stores null as address

head:- it always points to first Node of LL, advised not to change it's address

mover:- it points to Node previous to newly formed Node and changes Node's(previous Node's)
stored address to the next Node, and then moves to the next Node
initially mover points to first Node

temp:- it points to the newly formed Node, so that mover can move to to the newly formed Node
after changing stored address of previous Node

the function returns  head, which can be used to do various thing with the converted
array


*/

Node *ArrayToLL(vector<int> v)
{
    Node *head = new Node(v[0]); // creating a new Node(by DMA, using parametrised constructor)
    // v[0] is stored as data, next is NULL(due to constructor)
    Node *mover = head;
    // loop to create more nodes
    for (int i = 1; i < v.size(); i++) // starting from 1 as Node of v[0] is already created
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; // we address of head we can do various tasks in LL
}

/*Traversal in LL
to traverse in LL, we never tamper the position of the head, we use another
temp pointer(of Node data type), we stop when temp points to NULL

T.C O(N)
*/

// example:- a func to print all elements of and array after it was converted to LL

// IF NODE IS IMPLEMENTED IN TEMPLATE, USE node<int>* head=new...

void displayArrByLL(vector<int> v)
{
    Node *head = ArrayToLL(v); // array converted to LL
    Node *temp = head;         // DO NOT TAMPER HEAD

    while (temp) // will stop when temp==NULL
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*Length of an LL
just add a counter in displayfunction while loop
T.C O(N)
*/

int LenghtOfLL(vector<int> v)
{
    Node *head = ArrayToLL(v); // array converted to LL
    Node *temp = head;         // DO NOT TAMPER HEAD
    int cnt = 0;
    while (temp) // will stop when temp==NULL
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
/*search in LL
T.C O(n) (worst case)
*/
bool SearchInLL(vector<int> v, int k)
{
    Node *head = ArrayToLL(v);
    Node *temp = head;
    while (temp)
    {
        if (temp->data == k)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> v = {1, 3, 2, 7, 4};
    displayArrByLL(v);
    cout << LenghtOfLL(v) << endl;
    cout << SearchInLL(v, 33) << endl;
}
