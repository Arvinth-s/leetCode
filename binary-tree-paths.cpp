//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<string> dfs(TreeNode *root)
    {
        vector<string> res;
        if (!root)
            return res;
        if (root->left)
        {
            vector<string> left_res = dfs(root->left);
            for (auto s = left_res.begin(); s != left_res.end(); s++)
            {
                *s = to_string(root->val) + "->" + *s;
                res.push_back(*s);
            }
        }
        if (root->right)
        {
            vector<string> right_res = dfs(root->right);
            for (auto s = right_res.begin(); s != right_res.end(); s++)
            {
                *s = to_string(root->val) + "->" + *s;
                res.push_back(*s);
            }
        }

        if (!root->left && !root->right)
        {
            res.push_back(to_string(root->val));
        }
        return res;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        stack<int> st;
        res = dfs(root);

        return res;
    }
};