#include <iostream>
using namespace std;

// Binary Tree => every node has at most two children
// full binary tree => all levels are completely filled
// complete binary tree => all levels are completely filled except the last one and it has all nodes as left as possible.
// perfect binary tree => all leaf nodes are at the same level.
// balanced binary tree => height of tree at O(log n) (n => nodes) => the nodes are in a straight line and every node has one child.
// perfect tree :  the number of nodes in the tree (size)is 2 ^ levels - 1
// perfect tree :  the height = log(n+1)-1 (the base is 2 )
// for any binary tree
// the number of nodes = 2 ^ height (the maximum number)
// for l level => 2 ^ l -1 nodes in this level(the maximum)
// for n nodes => the min number of levels = ceil(log(n+1))
// for m leaves => the min number of levels is ceil(log m ) + 1
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// Traverse Preorder => root - left - right- O(n)
void traversePreOrder(Node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Traverse Inorder => left - root - right - O(n)
void traverseInOrder(Node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}

// Traverse Postorder => left - right - root - O(n)
void traversePostOrder(Node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Preorder traversal: ";
    traversePreOrder(root);
    cout << "\nInorder traversal: ";
    traverseInOrder(root);
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);

    return 0;
}
