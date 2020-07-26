/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if (!root)  return ans;
        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            ans.push_back(root->val);

            if (root->right)    st.push(root->right);
            if (root->left)    st.push(root->left);
        }
        return ans;
    }
};
// @lc code=end

