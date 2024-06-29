#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
// my leetcode submission => https://leetcode.com/problems/sum-of-left-leaves/submissions/1304040250/
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
    BinaryTree(int root_value) : root(new TreeNode(root_value)) {}

    void add(vector<int> data, vector<char> direction)
    {
        assert(data.size() == direction.size());
        TreeNode *current = this->root;
        // Iterate on the path, create all necessary TreeNodes
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
    // the problem 4 easy 
    class Solution
    {
    public:
        int sumOfLeftLeaves(TreeNode *root)
        {
            if (!root)
            {
                return 0;
            }
            int sum = 0;
            if (root->left && !root->left->left && !root->left->right) // here it is the left node and have no children in the right and left(leave node )
            {
                sum += root->left->data; // Add the value of the left leaf node
            }
            // Recursively find the sum of left leaves in both left and right subtrees
            return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right); // to traverse over the tree to reach the leave node
        }
    };
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

    BinaryTree::Solution sol;
    cout << "Sum of left leaves: " << sol.sumOfLeftLeaves(tree.root) << endl;
    // Should print the sum of all left leaves

    return 0;
}
