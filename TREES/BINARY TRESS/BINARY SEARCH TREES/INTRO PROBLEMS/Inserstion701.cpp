#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int x)
    {
        left = NULL;
        right = NULL;
        val = x;
    }
};

// insert a node such that it remains a BST  T.C O(log_2 N)

TreeNode *insertBSTMySol(TreeNode *root, int value)
{
    TreeNode *temp = root;
    TreeNode *prev = NULL;
    if (temp == NULL)
    {
        temp = new TreeNode(value);
        return temp;
    }
    while (temp != NULL)
    {
        if (temp->val > value)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if(prev->val>value&&prev->left==NULL)
    {
        prev->left= new TreeNode(value);
    }
    else//prev->value<value
    {
        prev->right=new TreeNode(value);
    }
    return root;
}
