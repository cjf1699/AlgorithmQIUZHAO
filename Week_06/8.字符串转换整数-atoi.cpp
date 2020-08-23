/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, total = 0, index = 0;
        while (index < str.length() && str[index] == ' ')   index++;
        if (index >= str.length())  return 0;
        if (str[index] == '+' || str[index] == '-') sign = str[index++] == '-' ? -1 : 1;
        while (index < str.length()) {
            int digit = str[index] - '0';
            if (digit < 0 || digit > 9) break;
            if (INT_MAX / 10 < total || INT_MAX / 10 == total && INT_MAX % 10 < digit)  return sign == 1 ? INT_MAX : INT_MIN;
            total = total * 10 + digit;
            index++;
        }
        return total * sign;
    }
};
// @lc code=end

