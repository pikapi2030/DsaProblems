#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
TreeNode* left;
TreeNode * right;
int val;
};

/* find diametre of BT, diametre is longest path lenght between two any two nodes
path need not to pass through root)
*/

/*BRUTE
we use maxDiametre argument to  store max diametre, we calculate diametre by summing up
depth of right and left
// !T.C O(N^2)
*/

int Depth(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(Depth(root->left), Depth(root->right));
}

int Brute(TreeNode*root, int &maxDiametre)//!call by reference important
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=Depth(root->left);
    int rh=Depth(root->right);
    int PathLength=lh+rh;

    maxDiametre= max(maxDiametre,PathLength);

    Brute(root->left,maxDiametre);
    Brute(root->right,maxDiametre);
    return maxDiametre;

}

/*Optimal
//!T.C O(N) S.C O(N)
we modify depth funtion, we return height as usuall but before return height we 
sum left height and right height and update our maxDiametre
*/

int ModifiedDepth(TreeNode *root,int &maxDiametre)
{

    if (root == NULL)
    {
        return 0;
    }

    int lh=ModifiedDepth(root->left,maxDiametre);
    int rh=ModifiedDepth(root->right,maxDiametre);
    maxDiametre=max(maxDiametre,lh+rh);//UPDATE MAX DIAMETRE
    return 1+max(rh,lh);//return height
    
}

int DiametreOpti(TreeNode*root)
{
    int maxDiametre=0;
    ModifiedDepth(root,maxDiametre);
    return maxDiametre;/*argument passed by reference so its value will change,
     which is what we return*/
}


