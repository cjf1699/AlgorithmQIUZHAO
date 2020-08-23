/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int idx = 0;
        if (!intervals.empty()) {
            ans.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] > ans[idx][1]) {
                    ans.push_back(intervals[i]);
                    idx++;
                } else {
                    ans[idx][1] = max(intervals[i][1], ans[idx][1]);
                }     
            }
        }
        return ans;
    }
};
// @lc code=end

