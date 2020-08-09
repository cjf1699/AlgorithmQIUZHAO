/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1;
                    maxSide = max(maxSide, dp[i + 1][j + 1]);
                }
            }
        } 
        return maxSide * maxSide;
    }
};
// @lc code=end

