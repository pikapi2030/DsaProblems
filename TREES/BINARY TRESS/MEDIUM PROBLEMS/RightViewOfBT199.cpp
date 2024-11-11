#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
TreeNode* left;
TreeNode * right;
int val;
};

/*Recursive aproach
we will perform a root right left travesal while maintaining a data structure storing right
view, we pass extra argument of level(level starts from 0), if level is equal to size of ds
 then we push in our ds other wise no
 T.C O(N)
 S.C O(H) (not considering the vector)
*/
void RightView(TreeNode*root, int level,vector<int>&v)
{
if(root==NULL)
{
    return;
}
if(level==v.size())
{
v.push_back(root->val);
}
RightView(root->right,level+1,v);
RightView(root->left,level+1,v);

}

vector<int>RV(TreeNode*root)
{
    vector<int>ans;
    RightView(root,0,ans);
    return ans;
}

/*Iterative aproach

*/

vector<int> RSV(TreeNode*root)
{
    queue<TreeNode*>qs;
    qs.push(root);
    int level=0;
    vector<int>v; 
   while(!qs.empty())
   {

        int size=qs.size();
        for(int i=0;i<size;i++)
        {
           TreeNode*current=qs.front();
           qs.pop();
           if(current->right!=NULL)
           {
            qs.push(current->right);
           }
           if(current->left!=NULL)
           {
            qs.push(current->left);
           }
           if(level==v.size())
           {
            v.push_back(current->val);
           }


        }
        level++;

   }
   return v;
}

