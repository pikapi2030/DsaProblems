#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

vector<int> AddReverseLeft(Node *root)//!ROOT NOT INCLUDED
{

    vector<int> v;
    stack<int> st;
    root=root->left;
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

vector<int> AddReverseRight(Node *root)//!ROOT NOT INCLUDED
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
    return ans;
}

vector<int> topView(Node *root)
{
   vector<int>ans; 
   if(root==NULL)
   {
    return ans;
   }

   vector<int>left=AddReverseLeft(root);
   vector<int>right=AddReverseRight(root);

   ans.insert(ans.end(),left.begin(),left.end());
   ans.push_back(root->data);
   ans.insert(ans.end(),right.begin(),right.end());


    return ans;
}
