#include <bits/stdc++.h>
using namespace std;
//!Inorder:- Left subtree,root,rightsubtree
//!right subtree is last child from the k child of a root
//making a kary tree of K=3
class Kary
{
   public:
 int data;
 Kary*child[3];

};

void Inorder(Kary*root)
{
if(root=NULL)
{
   return;
}
for(int i=0;i<2;i++)//Travesing all child except the last child
{
   Inorder(root->child[i]);
}
   cout<<root->data;
   Inorder(root->child[2]);//last child

}

void preorder(Kary*root)
{

if (root == NULL)

return;
   
cout<< root->data << " ";

for (int i = 0; i < 2; i++)
{
preorder(root->child[i]);
}
preorder(root->child[2]);

}
void postorder(Kary*root)
{

if (root == NULL)

return;


for (int i = 0; i < 2; i++)
{
preorder(root->child[i]);
}
preorder(root->child[2]);
cout<< root->data << " ";


}


