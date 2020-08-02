/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())   return -1;
        if (nums.size() == 1)   return nums[0] == target ? 0 : -1;
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)    return mid;
            if (nums[mid] >= nums[0]) {
                if (target >= nums[0] && nums[mid] > target)    hi = mid - 1;
                else    lo = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[hi])   lo = mid + 1;
                else    hi = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

