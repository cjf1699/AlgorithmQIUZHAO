class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())   return;
        // 1. 懵逼时候的想法： 数组拼接
        vector<int> tmp;
        int numOfNoneZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0){
                tmp.push_back(nums[i]);
                numOfNoneZero++;
            }
        }
        vector<int> zeros(nums.size() - numOfNoneZero, 0);
        tmp.insert(tmp.end(), zeros.begin(), zeros.end());

        nums = tmp;
        
        // 2. 双指针
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};