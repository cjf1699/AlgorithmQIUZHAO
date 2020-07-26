/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        if (root)   st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            for (auto node : root->children) {
               if (node)    st.push(node);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

