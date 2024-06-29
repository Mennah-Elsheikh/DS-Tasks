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
    // the problem 5 easy  => leetcode my submission here => https://leetcode.com/problems/cousins-in-binary-tree/submissions/1304097750/
    //(dfs aproach)=> the best one :)
    // or queue and pair => https://leetcode.com/problems/cousins-in-binary-tree/submissions/1304095773/
    // note : the solution here i have been searched for it to understad :)
    class Solution
    {
    public:
        struct NodeInfo
        {
            TreeNode *parent;
            int depth;
        };
        void dfs(TreeNode *node, TreeNode *parent, int depth, int data, NodeInfo &info)
        {
            if (!node)
            {
                return;
            }
            if (node->data == data)
            {
                info.parent = parent;
                info.depth = depth;
                return;
            }
            dfs(node->left, node, depth + 1, data, info);
            dfs(node->right, node, depth + 1, data, info);
        }

        bool isCousins(TreeNode *root, int x, int y)
        {
            if (!root)
            {
                return false;
            }

            NodeInfo infoX = {nullptr, 0};
            NodeInfo infoY = {nullptr, 0};

            dfs(root, nullptr, 0, x, infoX);
            dfs(root, nullptr, 0, y, infoY);

            // Check if the nodes are at the same depth but have different parents
            return (infoX.depth == infoY.depth) && (infoX.parent != infoY.parent);
        }
    };
    /*
    class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<pair<TreeNode*, TreeNode*>> q; // {node, parent}
        q.push({root, nullptr});

        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;
        int xDepth = -1;
        int yDepth = -1;
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) {
                    xParent = parent;
                    xDepth = depth;
                }
                if (node->val == y) {
                    yParent = parent;
                    yDepth = depth;
                }

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            if (xParent && yParent) break;
            depth++;
        }

        return (xDepth == yDepth) && (xParent != yParent);
    }
};
    */
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

    // Use the correct scope for Solution
    BinaryTree::Solution sol;
    cout << "Are 10 and 6 cousins? " << (sol.isCousins(tree.root, 10, 6) ? "Yes" : "No") << "\n";
    // Expected output: No
    return 0;
}
