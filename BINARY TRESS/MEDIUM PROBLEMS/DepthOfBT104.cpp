#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
TreeNode* left;
TreeNode * right;
int val;
};
//!T.C O(N)  S.C O(N)  worst case when every node has two children
int BFS_Solution(TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int level=0;
    queue<TreeNode*>qs;
    qs.push(root);

    while(!qs.empty())
    {
        int size=qs.size();
        for(int i=0;i<size;i++)
        {
            TreeNode*current=qs.front();
            qs.pop();
            if(current->left!=NULL)
            {
                qs.push(current->left);
            }
            if(current->right!=NULL)
            {
                qs.push(current->right);
            }
        }
        level++;
    }
    return level;
}

int RecursiveSol(TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(RecursiveSol(root->left),RecursiveSol(root->right));

}
//!T.C O(N)  S.C O(N)(auxillary space), worst case when every node has only one children

