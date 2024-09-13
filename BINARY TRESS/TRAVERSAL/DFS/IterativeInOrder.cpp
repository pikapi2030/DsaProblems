#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int var;
};

// left root right in iterative manner
//! stack used T.C O(N), S.C O(N) nearly equal to height of BT

vector<int> IterativeInOrder(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    TreeNode *temp = root;

    while (1)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            v.push_back(temp->var);
            temp = temp->right;
        }
    }
    return v;
}
