#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int height;
    int val;

    Node(int x)
    {
        left = NULL;
        right = NULL;
        height = 1;
        val = x;
    }
};

Node *deletion(Node *root)
{
    if (!root)
    {
        delete root;
        
    }
}