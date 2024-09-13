#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int var;
};
/*
preorder using iteration(root left right)
!!we use stack data structure,T.C O(N), S.C O(N) or nearly O(height)

*/

  vector<int> IterativePreOrder(Node *root)
{
    vector<int> v;
    if(root==NULL)
    {
        return v;
    }
    stack<Node*> st;
    st.push(root);
    while (!st.empty())
    {
        Node *top = st.top();
        v.push_back(top->var);
        st.pop();
        if (top->right != NULL)
        {
            st.push(top->right); //! First push right, then left as we are using stack which reverses the order
        }
        if (top->left != NULL)
        {
            st.push(top->left);
        }
    }
}
