/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')    return 0;
        int first = 1, second = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); i++) {
            int temp = 0;
            if (s[i] != '0')    temp += second;
            temp += (isAlpha(str2int(s.substr(i - 1, 2))) ? first : 0);
            first = second;
            second = temp;
        }
        return second;
    }
    inline int str2int(string s) {
        return (s[0] - '0') * 10 + s[1] - '0';
    }
    inline bool isAlpha(int n) {
        return n >= 10 && n <= 26;
    }
};
// @lc code=end

