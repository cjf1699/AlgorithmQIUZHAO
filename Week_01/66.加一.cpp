/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        int n = digits.size();
        for (i = n - 1; i >= 0; i--) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] > 0)  break;
        }
        if (i < 0) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
// @lc code=end

