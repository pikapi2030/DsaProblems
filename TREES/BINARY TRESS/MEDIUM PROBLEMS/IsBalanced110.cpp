#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

// check if tree is balanced or not
//! Condition, (height of left-height of right)<=1

// aproach 1- use BFS to calculate height and nu

int Depth(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(Depth(root->left), Depth(root->right));
}
//BRUTE:-  T.C O(N)*O(N) (one for finding height and other for traversal)  
bool Brute(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (abs(Depth(root->left) - Depth(root->right)) > 1)
    {
        return false;
    }
    else
    {
        return (Brute(root->left)&&Brute(root->right));
        
    }
}

/*optimal
we will modify our depth function such that if our tree is not balanced, it return -1
other wise it returns height, the moment it returns -1, we say tree is not balanced(in bool function)

//!T.C O(N) 
*/

int ModiFiedDepth(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int Rh=ModiFiedDepth(root->right);
    int Lh=ModiFiedDepth(root->left);
     if(Lh==-1||Rh==-1)
     {
        return -1;
     }

    if(abs(Lh-Rh)>1)//tree not balanced
    {
    return -1;
    }
    else
    {
        return 1+max(Rh,Lh);
    }

}

bool OPTI(TreeNode*root)
{
    if(ModiFiedDepth(root)==-1)
    {
        return false;
    }
    return true;
}



