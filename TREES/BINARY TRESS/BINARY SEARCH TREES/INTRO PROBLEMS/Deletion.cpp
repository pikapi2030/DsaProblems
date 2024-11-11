#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};
/*delete a given node in a BST such that the resultant BT is also a BST
//!Multiple answers possible
*/

/*aproach:1
step 1:
we will search for the node to be deleted, asume that node as target, R.O.T as R.O.T
L.O.T as Left of target, P.0.T as Parent Of Target

step 2:
we know L.O.T is smaller than R.O.T ,
so we will delete target and connect L.O.T to P.O.T(left side of parent),
now we have to connect the R.O.T, we wil simply
find the largest element in L.O.T and connect R.O.T
to that node (ON RIGHT SIDE)

*/

/*aproach:2

step 1:
we will search for the node to be deleted, asume that node as target

step2:

we know R.O.T is larger than L.O.T and P.O.T so we will erase target and connect R.O.T
to right of P.O.T, now we have to connect L.O.T, we will simply find smallest
element in R.O.T and connect L.O.T in that node(AT RIGHT SIDE)
*/

bool isLeaf(TreeNode*root)
{
   if(root->left==NULL&&root->right==NULL)
   {
    return true;
   }
   return false;
}

TreeNode *maximumNode(TreeNode *root)
{
    TreeNode *ans = NULL;
    while (root != NULL)
    {
        ans = root;
        root = root->right;
    }
    return ans;
}

pair<TreeNode *, TreeNode *> TargetSearch(TreeNode *root, int val)
{
    TreeNode *prev = NULL;

    while (root != NULL && root->val != val)
    {
        if (root->val > val)
        {
            prev = root;
            root = root->left;
        }
        else
        {
            prev = root;
            root = root->right;
        }
    }
    return {prev, root};
}

TreeNode *Mysol(TreeNode *root, int val)

{
    TreeNode *temp = root;
    TreeNode *PrevOfTarget = TargetSearch(temp, val).first;
    TreeNode *target = TargetSearch(temp, val).second;

    if (target == NULL)
    {
        return root;
    }

    if (target == root)
    {
        if(isLeaf(root))
        {
            return NULL;

        }
        if (target->right != NULL)
        {
            target->right->left = target->left;
        }
        else
        {
            delete target;
        }
        return root;
    }
    if (isLeaf(target))
    {
        delete target;
        return root;
    }
    if (target->left == NULL)
    {
        PrevOfTarget->right = target->right;
        delete target;
        return root;
    }
    if (target->right == NULL)
    {
        PrevOfTarget->left = target->left;
        delete target;
        return root;
    }
    
    if(target->left->val>PrevOfTarget->val)
    {
    PrevOfTarget->right = target->left; // L.O.T conndected to P.O.T
    }
    else
    {
        PrevOfTarget->left=target->left;
    }
    TreeNode *MaxNodeOfLeftOfTarget = maximumNode(target->left);
    MaxNodeOfLeftOfTarget->right = target->right;
    delete target;
    return root;
}
