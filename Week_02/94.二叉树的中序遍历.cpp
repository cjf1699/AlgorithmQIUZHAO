/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> ans;
        TreeNode* curr = root;
        while(curr || !S.empty()){
            while(curr){
                S.push(curr);
                curr = curr->left;
            }
            curr = S.top(); 
            S.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;   
    }
};
// @lc code=end

