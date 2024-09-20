#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

void LeftADD(TreeNode *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->val);

    if (root->left != NULL)
        LeftADD(root->left, ans);
    else if (root->right != NULL)
        LeftADD(root->right, ans);
}

void ADDleaf(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->val);
        return;
    }
    ADDleaf(root->left, ans);
    ADDleaf(root->right, ans);
}

void ADDReverseRight(TreeNode *root, vector<int> &ans)
{
    stack<int> st;
    TreeNode *temp = root;

    while (temp != NULL)
    {
        st.push(temp->val);
        if (temp->right != NULL)
            temp = temp->right;
        else
            temp = temp->left;
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> BoundaryTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // Add the left boundary
    LeftADD(root->left, ans);

    // Add the leaf nodes
    ADDleaf(root, ans);

    // Add the right boundary in reverse order
    vector<int> rightBoundary;
    ADDReverseRight(root->right, rightBoundary);
    ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());

    return ans;
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = BoundaryTraversal(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
