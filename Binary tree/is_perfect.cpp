#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;
// Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.
// the number of nodes on path from root to leaf is 2^h – 1 nodes.(h => height)
// for more informations look here => https://www.geeksforgeeks.org/check-weather-given-binary-tree-perfect-not/
// TreeNode definition
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BinaryTree definition
struct BinaryTree
{
    TreeNode *root;

    BinaryTree(int root_value) : root(new TreeNode(root_value)) {}

    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());
        TreeNode *current = this->root;
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(values[i]);
                else
                    assert(current->left->val == values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(values[i]);
                else
                    assert(current->right->val == values[i]);
                current = current->right;
            }
        }
    }

    void _printInorder(TreeNode *current)
    {
        if (!current)
            return;
        _printInorder(current->left);
        cout << current->val << " ";
        _printInorder(current->right);
    }

    void printInorder()
    {
        _printInorder(root);
        cout << "\n";
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

// Solution class
class Solution
{
public:
    int findADepth(TreeNode *node)
    {
        int d = 0;
        while (node != nullptr)
        {
            d++;
            node = node->left;
        }
        return d;
    }

    /* This function tests if a binary tree is perfect
       or not. It basically checks for two things :
       1) All leaves are at the same level
       2) All internal nodes have two children */
    bool isPerfectRec(TreeNode *root, int d, int level = 0)
    {
        if (root == nullptr)
            return true;

        if (root->left == nullptr && root->right == nullptr)
            return (d == level + 1);

        if (root->left == nullptr || root->right == nullptr)
            return false;

        return isPerfectRec(root->left, d, level + 1) &&
               isPerfectRec(root->right, d, level + 1);
    }

    // Wrapper over isPerfectRec()
    bool isPerfect(TreeNode *root)
    {
        int d = findADepth(root);
        return isPerfectRec(root, d);
    }

    //================================================================================================================//
    // time complexity => O(n) , space complexity => O(n)
    bool isPerfect2(TreeNode *root)
    {
        // If one child is null and the other is not, the tree is not perfect
        if ((root->left == nullptr) != (root->right == nullptr))
            return false;
        // If the left child is null, and the right child is also null, it's perfect=> leave nodes
        if (root->left == nullptr)
            return true;
        // Check recursively for subtrees => they should be in the same level
        if ((root->left->left == nullptr) != (root->right->left == nullptr))
            return false;
        // Recursively check left and right subtrees=> if the left or right is not pefect the wall tree is not also .
        if (!isPerfect2(root->left) || !isPerfect2(root->right))
            return false;
        // If all conditions are satisfied, the tree is perfect
        return true;
    }

    //========================================================================================================================//
    // This functions gets the size of binary tree
    // Basically, the number of nodes this binary tree has
    // the number of nodes on path from root to leaf is 2^h – 1 nodes.(h => height)
    // the way 2 => we will use the formula if the size of the tree expected == the number of provided tree => the tree is perfect
    int getLength(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + getLength(root->left) + getLength(root->right);
    }

    // Returns True if length of binary tree is a power of 2 else False
    // bool isPerfect3(TreeNode *root)
    // {
    //     int length = getLength(root);
    //     return (length & (length + 1)) == 0;
    // }
    bool isPerfect3(TreeNode *root)
    {
        int height = findADepth(root);
        int nodes = getLength(root);

        return nodes == (1 << height) - 1;
    }

    //=======================================================================================================================//
    // Function to check if the given binary tree is a perfect
    // binary tree
    // from my search :)
    bool isPerfectBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root);

        int level = 1; // Current level of the tree
        int flag = 1;  // Flag to track if the tree is perfect or not

        while (!q.empty())
        {
            int size = q.size();
            vector<int> levelValues;

            // Traverse all nodes at the current level
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                levelValues.push_back(temp->val);

                // Enqueue the left and right children of the current node
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            // Check if the number of nodes at the current level
            // is not zero and not equal to the expected level size
            if (levelValues.size() != 0 && levelValues.size() != level)
            {
                flag = 0; // Tree is not perfect
            }

            // Update the expected level size for the next level
            level = level * 2;
        }

        return flag;
    }
};

int main()
{
    BinaryTree tree(1);

    tree.add({2}, {'L'});
    tree.add({3}, {'R'});
    tree.add({4}, {'L'});
    tree.add({5}, {'R'});
    tree.add({6}, {'L'});
    tree.add({7}, {'R'});

    Solution sol;

    TreeNode *root = tree.getRoot();

    // Test isPerfectRec function
    assert(sol.isPerfect(root));

    // Test isPerfect2 function
    assert(sol.isPerfect2(root));

    // Test isPerfect3 function
    assert(sol.isPerfect3(root));

    // Test isPerfectBinaryTree function
    assert(sol.isPerfectBinaryTree(root));

    cout << "All tests passed!\n";

    return 0;
}
