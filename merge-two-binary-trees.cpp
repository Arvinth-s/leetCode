//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *merge(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *left = NULL, *right = NULL;
        int x = 0, y = 0;
        if (!root1 && !root2)
        {
            return NULL;
        }
        else if (root1 && root2)
        {
            x = root1->val;
            y = root2->val;
            left = merge(root1->left, root2->left);
            right = merge(root1->right, root2->right);
            return new TreeNode(root1->val + root2->val, left, right);
        }
        else if (root1)
        {
            left = merge(root1->left, NULL);
            right = merge(root1->right, NULL);
            return new TreeNode(root1->val, left, right);
        }
        else
        {
            left = merge(root2->left, NULL);
            right = merge(root2->right, NULL);
            return new TreeNode(root2->val, left, right);
        }
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return merge(root1, root2);
    }
};