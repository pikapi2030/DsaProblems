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

//! root at last
// left right root

void PostOrder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->Right);
    cout<<root->var;
}
