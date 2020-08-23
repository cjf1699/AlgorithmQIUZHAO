/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), begin = 0, maxLen = 1;
        if (len < 2)    return s;
        for (int i = 0; i < 2 * len - 1; i++) {
            int left = i / 2, right = i / 2 + (i & 1);
            int temp = left == right ? -1 : 0;
            while (left >= 0 && right < len && s[left] == s[right]) {
                temp += 2;                
                left--;
                right++;
            }
            if (temp > maxLen) {
                begin = left + 1;
                maxLen = temp;
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end

