/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);        
        int i = left, m = left, j = mid + 1, n = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] / 2.0 > nums[j]) {
                ans += mid - i + 1;
                j++;
            } else  i++;
        }
        // merge 
        while (m <= mid && n <= right)  temp[k++] = nums[m] < nums[n] ? nums[m++] : nums[n++];
        while (m <= mid)   temp[k++] = nums[m++];
        while (n <= right)   temp[k++] = nums[n++];
        for (int idx = 0; idx < right - left + 1; idx++)    nums[idx + left] = temp[idx];
    }
};
// @lc code=end

