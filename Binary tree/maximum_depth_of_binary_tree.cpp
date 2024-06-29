#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
// leetcode my submission => https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1303845329/
//  the dfs way => https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1303847334/
//  Definition for a binary tree node.
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
    /*
    class Solution
    {
    public:
        int maxDepth(TreeNode *root)
        {
            int maxDepth = 0; // Initialize the maximum depth
            int count = 0;    // Initialize the current depth counter
            dfs(root, count, maxDepth);
            return maxDepth;
        }

    private:
        void dfs(TreeNode *node, int count, int &maxDepth)
        {
            if (node == NULL)
                return;
            count++; // Increment counter to reflect current depth
            if (count > maxDepth)
            {
                maxDepth = count; // Update maximum depth
            }
            dfs(node->left, count, maxDepth);
            dfs(node->right, count, maxDepth);
        }
        */
    // another simple way
    // problem 2 easy
    class Solution
    {
    public:
        int maxDepth(TreeNode *node)
        {
            if (node == nullptr)
                return 0;
            int left_depth = maxDepth(node->left);
            int right_depth = maxDepth(node->right);
            return max(left_depth, right_depth) + 1;
        }
    };

    int maxDepth()
    {
        Solution sol;
        return sol.maxDepth(root);
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

    cout << "The max depth is: " << tree.maxDepth() << endl;

    return 0;
}
