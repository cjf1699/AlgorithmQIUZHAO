/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 1. 最后一个用例超时
        if (nums.empty())   return;
        k %= nums.size();
        for (int i = 0; i < k; i++) {
            int target = nums[nums.size() - 1];
            for (int j = nums.size() - 2; j >= 0; j--) {
                nums[j+1] = nums[j]; 
            }
            nums[0] = target;
        }
        // 2. 开启新数组
        if (nums.empty())   return;
        k %= nums.size();

        vector<int> back(nums.end() - k, nums.end());
        vector<int> top(nums.begin(), nums.begin() + nums.size() - k);
       
    
        vector<int> newNum;
        
        newNum.insert(newNum.end(), back.begin(), back.end());
        newNum.insert(newNum.end(), top.begin(), top.end());
        
        nums = newNum;
        // 3. 环状替换
        if (nums.empty())   return;
        int n = nums.size();
        k %= n;
        int cnt = 0;
        for (int start = 0; cnt < n; start++) {
            int cur = start;
            int prev = nums[start];            
            do {
                int next = (cur + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                cur = next;
                prev = temp;
                cnt++;
            } while (start != cur);
        }
        // 4. 反转数组
        if (nums.empty())   return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

