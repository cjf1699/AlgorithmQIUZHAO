/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            ans++;
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < len && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
            l = i - 1, r = i;
            while (l >= 0 && r < len && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};
// @lc code=end

