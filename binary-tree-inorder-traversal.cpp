/**
 //OM NAMO NARAYANA
 //https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

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
class Solution {
public:
    
    void inorderUtil(TreeNode* root, vector<int>&res){
        if(root->left){
            inorderUtil(root->left, res);
        }
        res.push_back(root->val);
        if(root->right){
            inorderUtil(root->right, res);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return vector<int>{};
        vector<int> res;
        inorderUtil(root, res);
        return res;
    }
};