/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int count = 0;
        for (char ch : tasks) {
            mp[ch]++;
            count = max(count, mp[ch]);
        }
        int ans = (count - 1) * (n + 1);
        for (auto it : mp)  if (it.second == count)    ans++;
        return max((int)tasks.size(), ans);
    }
};
// @lc code=end

