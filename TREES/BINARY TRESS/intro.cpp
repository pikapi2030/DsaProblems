#include <bits/stdc++.h>
using namespace std;
/*
root- top node of Bt
leaf- a node with no children
ancestor- node above a given node(of those given node is chilren of)
TYPES of BT
1. full BT: every node has 0 or 2 children
2.complete BT: all levels are completly filled, last level may have incomplete nodes but those
incompelete nodes must be as left as possible
3. perfect BT:- all leaft nodes at same level
4. Balanced binary trees:  (absolute(height of left-height of right))<=1 for every node(//!absolute difference)
5. Degenrate trees : every node has single children
*/

//! implemantation: impelemented using a node having a left, right pointer and a data var

class Node
{
    Node *left;
    Node *Right;
    int var;

    Node(int data)
    {
        left = NULL;
        Right = NULL;
        var = data;
    }
};

