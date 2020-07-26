/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        if (!root)  return {};
        stack<Node*> st;
        st.push(root);
        vector<int> ans;
        while (!st.empty()) {
            Node* _top = st.top();
            st.pop();
            ans.push_back(_top->val);
            for (int i = _top->children.size() - 1; i >= 0; i--) {
                if (_top->children[i])  st.push(_top->children[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

