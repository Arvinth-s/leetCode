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
    //first:maximum value including the root node
    //second: maximum value without the root node
    vector<int> recur(TreeNode *root)
    {
        if (!root)
            return vector<int>{0, 0};
        vector<int> left = recur(root->left), right = recur(root->right);
        assert(left.size() == 2 && right.size() == 2);
        return vector<int>{root->val + left[1] + right[1], max(left[0], left[1]) + max(right[0], right[1])};
    }

    int rob(TreeNode *root)
    {
        vector<int> res = recur(root);
        return max(res[0], res[1]);
    }
};