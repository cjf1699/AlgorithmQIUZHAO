/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            vector<bool> vis;
            dfs(nums, temp, i, vis);
        }
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& temp, int n, vector<int>& vis) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                temp.push_back(i);
                vis[i] = true;
                dfs(nums, temp, n, vis);
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

