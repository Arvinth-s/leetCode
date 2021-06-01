//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
faster than 66%
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    pair<bool, bool> recur(TreeNode* root, int p, int q, int &ans, bool &fixed){
        
        if(!root || fixed)return pair<bool, bool>(false,false);
        
        pair<bool, bool> res(false, false), left(false, false), right(false, false);

        left=recur(root->left, p, q, ans, fixed);
        right=recur(root->right, p, q, ans, fixed);
        
        
        res.first |= left.first | right.first |root->val==p;   
        res.second |= left.second | right.second | root->val==q;
        

        
        if(res.first && res.second){
            ans=root->val;
            fixed=true;
            return pair<int, int>(false, false);
        }
        
        return res;
        

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int ans=0;
        bool fixed=false;
        recur(root, p->val, q->val, ans, fixed);
        return new TreeNode(ans);
    }
};