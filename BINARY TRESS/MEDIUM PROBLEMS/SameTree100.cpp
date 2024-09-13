#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
TreeNode* left;
TreeNode * right;
int val;
};
//check if two given trees are identical or not  T.C O(N)  S.C O(N)

bool isIdentical(TreeNode *r1,TreeNode *r2)
{
    if(r1==NULL||r2==NULL)//if one of them is NULL then other should be NULL(else they are not identical)
    {
        return (r1==r2);
    }
    
    return (r1->val==r2->val)&&isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right);
}

