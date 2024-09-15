#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};
// Do clockwise and anticlokwise boundary traversal
//! boundary traversal may or may not include all nodes

// Anti-clockwise




vector<int> LeftADD(TreeNode *root)
{
    vector<int> ans;
    ans.push_back(root->val);
    TreeNode *temp = root->left;
    // inserting all left nodes
    while (1)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            break;
        }
        while (temp != NULL)
        {

            ans.push_back(temp->val);
            temp = temp->left;
        }
        temp = temp->right;
        ans.push_back(temp->val);
    }
    return ans;
}

vector<int> ADDleaf(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ADDleaf(root->left);
    ans.push_back(root->val);
    ADDleaf(root->right);
}

vector<int> ADDReverseRight(TreeNode *root)
{
    vector<int> ans;
    stack<int> st;
    TreeNode*temp=root;
    while (1)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.top();
            }
            return ans;
        }
        while(temp->right!=NULL)
        {
        temp=temp->right;
        ans.push_back(temp->val);
        }
        temp=temp->left;
        ans.push_back(temp->val);

    }
}

vector<int>BoundaryTraversal(TreeNode*root)
{
    vector<int>ans;
    
}
