#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
TreeNode* left;
TreeNode * right;
int val;
};


bool isSameTree(TreeNode *r1,TreeNode *r2)
{
    if(r1==NULL||r2==NULL)//if one of them is NULL then other should be NULL(else they are not identical)
    {
        return (r1==r2);
    }
    
    return (r1->val==r2->val)&&isSameTree(r1->left,r2->left)&&isSameTree(r1->right,r2->right);
}



    bool isSymmetric(TreeNode* root) 
    {
        return isSameTree(root->left,root->right);
    }


