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


//!root remanins at centre
//https://youtu.be/jmy0LaGET1I?feature=shared
/*
we trverse by following the rule //!left root right

we go to a node and check if it has childes, if yes then go to left child, till no child
then go back to parent(here root) of current child then left of the root,
repeat this
*/

void InOrder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
 
    InOrder(root->left);
    cout<<root->var;
    InOrder(root->Right);

}

