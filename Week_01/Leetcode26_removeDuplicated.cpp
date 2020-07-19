class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())   return 0;
        int lastNoRepeat = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[lastNoRepeat])  continue;
            nums[++lastNoRepeat] = nums[i];
        }
        return lastNoRepeat + 1;
    }
};