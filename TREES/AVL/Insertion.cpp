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

int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int getBalance(Node *root)
{
    return (getHeight(root->left)) - (getHeight(root->right));
}

Node *rightRotate(Node *root) // unbalanced root is passed,
{

    Node *leftChild = root->left;
    Node *leftCHILDRight = root->left->right;

    leftChild->right = root;
    root->left = leftCHILDRight;

    // Update height of root and left child of root
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));

    return leftChild; //!!returning leftchild(of root) adress to be connected with orignal parent of root
}

Node *leftRotate(Node *root)
{
    Node *rightChild = root->right;
    Node *rightChildleft = rightChild->left;

    rightChild->left = root;
    root->right = rightChildleft;

    // Update height of root and left child of root
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));

    return rightChild;
}

Node *insert(Node *root, int key)

{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (root->val > key)
    {
        root->left = insert(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = insert(root->right, key);
    }
    else //! No Duplicates allowed
    {
        return root;
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check Balance
    int balance = getBalance(root);

    // Performing balancing

    if (balance > 1)
    {
        if (key < root->left->val) //! LL Perfrom Right rotation
        {
            return rightRotate(root);
        }
        else if (key > root->left->val) //! LR Perfrom Left rotation then right rotation
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    else if (balance < -1)
    {
        if (key < root->right->val) //! RL  perfrom Right rotation then left rotation
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        else if (key > root->right->val) //! RR  Pefrom left rotation
        {
            return leftRotate(root);
        }
    }

    else // No Balancing needed
    {
        return root;
    }
}

void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << " " << root->val << " ";
    inOrder(root->right);
}

int main()

{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 19);
    root = insert(root, 23);
    root = insert(root, 60);
    root = insert(root, 1);
    root = insert(root, 56);
    root = insert(root, 33);
    inOrder(root);
}
