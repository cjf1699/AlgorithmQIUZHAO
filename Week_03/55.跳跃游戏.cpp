/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())   return false;
        int endReachable = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= endReachable)    endReachable = i;
        }
        return endReachable == 0;
    }
};
// @lc code=end

