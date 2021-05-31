//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
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
    void recur(TreeNode *root)
    {
        if (!root)
            return;
        recur(root->left);
        recur(root->right);
        if (!root->left)
            return;

        TreeNode *crawl = root->left;
        while (crawl->right)
        {
            crawl = crawl->right;
        }

        crawl->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    void flatten(TreeNode *root)
    {
        recur(root);
    }
};