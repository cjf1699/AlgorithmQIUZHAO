class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 暴力解
        if (nums.empty())    return {};

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};

        // 两遍哈希表
        if (nums.empty())    return {};
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i< nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end() && i != mp[target - nums[i]])  return {i, mp[target - nums[i]]};
        }

        return {};
        
        // 一遍哈希表
        if (nums.empty())    return {};
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end())  return {i, mp[target - nums[i]]};
            mp[nums[i]] = i;
        }

        return {};
    }
};