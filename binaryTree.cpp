// Simple binary tree in C++

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Print left -> root -> right
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Print root -> left -> right
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Print left -> right -> root
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // Build this tree by hand:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder:   ";
    inorder(root);
    cout << endl;

    cout << "Preorder:  ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}