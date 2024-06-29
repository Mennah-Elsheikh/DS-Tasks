#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
// my submission in leetcode => https://leetcode.com/problems/path-sum/submissions/1304022019/
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

    bool isLeaf(TreeNode *node)
    {
        return node && !node->left && !node->right;
    }
    // the problem 3 easy 
    class Solution
    {
    public:
        bool hasPathSum(TreeNode *root, int targetSum)
        {
            if (!root)
            {
                return false;// the function will stop 
            }
            targetSum -= root->data;
            if (targetSum == 0 && !root->left && !root->right)
            {
                return true; // the all tree nodes is visited and the target sum is found 
            }
            return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);//the sum is found 
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
    cout << "Has path sum 12: " << sol.hasPathSum(tree.root, 12) << endl;

    return 0;
}
