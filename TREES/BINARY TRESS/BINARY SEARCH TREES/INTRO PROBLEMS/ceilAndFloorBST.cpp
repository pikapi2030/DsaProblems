#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
Node* left;
Node * right;
int data;
};
//q1:Given a key, return a number just greater than or equal to data(ceil)
//T.C O(log_2 N)

int CEILBST(Node*root,int key)
{

int ans=-1;
while(root!=NULL)
{
if(root->data==key)
{
    return key;
}

else if(root->data>key)
{
ans=root->data;
root=root->left;
}
else
{
    root=root->right;
}

}
return ans;

}

//q2:given a key, return a node value just samller than or equal to key
//T.C O(log _2 N)
int FloorBST(Node*root,int key)
{

int ans=-1;
while(root!=NULL)
{
if(root->data==key)
{
    return key;
}

else if(root->data>key)
{
root=root->left;
}
else
{
    ans=root->data;

    root=root->right;
}

}
return ans;

}

