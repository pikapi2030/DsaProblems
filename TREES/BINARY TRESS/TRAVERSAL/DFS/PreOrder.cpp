#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *left;
    Node *Right;
    int var;

    Node(int data)
    {
        left = NULL;
        Right = NULL;
        var = data;
    }
};

//!root remains at first
/*
we traverse like root left right
https://youtu.be/jmy0LaGET1I?feature=shared
*/

//!T.C O(N)
//!S.C O(N) (height of tree)(space used in recursion)
void PreOrder(Node* root)
{
    if(root==NULL)//base case
    {
        return;
    }
    cout<<root->var;
    PreOrder(root->left);//!calling for left
    PreOrder(root->Right);//!for right
}
