#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>
using namespace std;
struct TreeNode
{
    int data{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(int data) : data(data) {}
};

struct BinaryTree
{
    TreeNode *root{};
    BinaryTree(int root_dataue) : root(new TreeNode(root_dataue)) {}

    void add(vector<int> data, vector<char> direction)
    {
        assert(data.size() == direction.size());
        TreeNode *current = this->root;
        // iterate on the path, create all necessary TreeNodes
        for (int i = 0; i < (int)data.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(data[i]);
                else
                    assert(current->left->data == data[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(data[i]);
                else
                    assert(current->right->data == data[i]);
                current = current->right;
            }
        }
    }

    void _print_inorder(TreeNode *current)
    {
        if (!current)
            return;
        _print_inorder(current->left);
        cout << current->data << " ";
        _print_inorder(current->right);
    }

    void print_inorder()
    {
        _print_inorder(root);
        cout << "\n";
    }

    void _print_preorder(TreeNode *current)
    {
        if (!current)
            return;
        cout << current->data << " ";
        _print_preorder(current->left);
        _print_preorder(current->right);
    }

    void print_preorder()
    {
        _print_preorder(root);
        cout << "\n";
    }

    void _print_postorder(TreeNode *current)
    {
        if (!current)
            return;
        _print_postorder(current->left);
        _print_postorder(current->right);
        cout << current->data << " ";
    }

    void print_postorder()
    {
        _print_postorder(root);
        cout << "\n";
    }
    // the problem 1 easy
    int _tree_max(TreeNode *current)
    {
        if (!current)
            return 0;
        int ans = current->data;
        int left_max = _tree_max(current->left);
        int right_max = _tree_max(current->right);
        return max(ans, max(left_max, right_max));
    }

    void tree_max()
    {
        int max_value = _tree_max(root);
        cout << "The maximum number is: " << max_value << endl;
    }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    cout << "Inorder traversal: ";
    tree.print_inorder();
    // 7 4 8 2 5 9 1 3 10 6

    cout << "Preorder traversal: ";
    tree.print_preorder();
    // 1 2 4 7 8 5 9 3 6 10

    cout << "Postorder traversal: ";
    tree.print_postorder();
    // 7 8 4 9 5 2 10 6 3 1

    tree.tree_max();
    return 0;
}
