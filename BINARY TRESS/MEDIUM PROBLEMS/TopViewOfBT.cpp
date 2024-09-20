#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

vector<int> AddReverseLeft(Node *root)
{

    vector<int> v;
    stack<int> st;
    while (root != NULL)
    {
        st.push(root->data);
        root = root->left;
    }
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}

vector<int> AddReverseRight(Node *root)
{
    vector<int> ans;
    root = root->right;
    stack<int> st;

    while (root != NULL)
    {
        st.push(root->data);
        root=root->right;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> TopView(Node *root)
{
   vector<int>ans; 
   if(root==NULL)
   {
    return ans;
   }

   vector<int>left=AddReverseLeft(root);
   vector<int>right=AddReverseRight(root);

   merge(left.begin(),left.end(),right.begin(),right.end(),ans.begin());

    return ans;
}
