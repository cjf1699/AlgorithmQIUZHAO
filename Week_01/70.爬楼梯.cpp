/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    
    int climbStairs(int n) {
        // 1. 暴力递归, 超时
        if (n <= 2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
        
        // 2. 记忆化搜索 + 递归
        vector<int> dp(n + 1, -1);
        return helper(dp, n);

        // 3. 动态规划
        if (n <= 2) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] =  dp[i - 1] + dp[i - 2];
        }
        return dp[n];        

        // 4. 动态规划+空间优化
        if (n <= 2) return n;

        int one = 1, second = 2, three;
        for (int i = 3; i <= n; i++) {
            three = one + second;
            one = second;
            second = three;
        }
        return three;
    }

    
    int helper(vector<int>& dp, int n) {
        if (n <= 2) return n;
        if (dp[n] > 0)  return dp[n];
        dp[n] = helper(n - 1) + helper(n - 2);
        return dp[n];
    }
};
// @lc code=end

