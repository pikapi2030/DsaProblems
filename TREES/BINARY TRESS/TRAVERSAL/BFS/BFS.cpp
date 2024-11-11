#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int var;
};

//! left right next level

vector<int> BFS1(Node *root) //! 1D vector is returned(level is not taken care of, only the order)
{
    vector<int> v;
    queue<Node *> qs;
    qs.push(root);
    while (!qs.empty())
    {
        Node *curr = qs.front();
        qs.pop();
        if (curr->left != NULL)
        {
            qs.push(curr->left);
        }
        if (curr->right != NULL)
        {
            qs.push(curr->right);
        }
        v.push_back(curr->var);
    }
    return v;
}

vector<vector<int>> BFS2(Node *root)
{
    //!T.C O(N)
    //! S.C O(N)+O(N/2)  queue at max will hold the widest level of elements, other N is of vector
    queue<Node *> qs;
    vector<vector<int>> v;
    qs.push(root);
    int Level = 0; // in vector index from 0, so level starts from 0
if(root==NULL)
{
    return v;
}
    while (!qs.empty())
    {
        v.push_back(vector<int>());//!new level to avoid run time error(adding empty space)
        int SizeOfQs = qs.size();
        for (int i = 0; i < SizeOfQs; i++)
        {
            Node *current = qs.front();
            qs.pop();
            if (current->left != NULL)
            {
                qs.push(current->left);
            }
            if (current->right != NULL)
            {
                qs.push(current->right);
            }
            v[Level].push_back(current->var);
        }
        Level++; //! next level
    }
    return v;
}
