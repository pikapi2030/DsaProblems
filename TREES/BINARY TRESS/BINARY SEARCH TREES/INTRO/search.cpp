#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
TreeNode* left;
TreeNode * right;
int val;
};

//  T.C O(LOG N)  S.C O(H)  (if recursive)
//T.C if skewed tree O(N)


//recursive code:-

    TreeNode* searchBST(TreeNode* root, int val) 
    {
     if(root==NULL)
     {
        return NULL;
     }
     if(root->val==val)
     {
        return root;
     }

     if(root->val>val)
     {
       return  searchBST(root->left,val);
     }
     else
     {
        return searchBST(root->right,val);
     }   
    return NULL;
    }

//iterative code
//T.C O(log N), T.C if skewed O(N)
//S.C O(1)
TreeNode* BSTiterative(TreeNode*root,int val)
{
    
    while( root!=NULL&&root->val!=val )
    {
        if(root->val>val)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return root;
}




