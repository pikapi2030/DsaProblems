#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

// return the maximum sum of nodes from a path(path can exist between any two nodes)



   
int sum(TreeNode *root, int &MaxSum)
{
    if (root == NULL)
    {
        return 0;
    }
    int LeftSum = sum(root->left, MaxSum);
    int RightSum = sum(root->right, MaxSum);

    if (LeftSum < 0)
    {
        LeftSum = 0;
    }
    if (RightSum < 0)
    {
        RightSum = 0;
    }

    int Currentsum = root->val + max(LeftSum, RightSum);

    MaxSum = max(MaxSum, LeftSum + RightSum + root->val);
    MaxSum = max(MaxSum, root->val);

    return Currentsum;
}

int opti(TreeNode *root)

{
    int maxSUMS = INT_MIN;
    sum(root, maxSUMS);
    return maxSUMS;
}
