// 1. 暴力超时
// int maxArea(vector<int>& nums) {
//     int ans = INT_MIN;
//     for (int i = 0; i < nums.size() - 1; i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             int height = min(nums[i], nums[j]);
//             ans = max(ans, height * (j - i));
//         }
//     }
//     return ans;
// }
// 2. 双指针,左右夹逼   
int maxArea(vector<int>& nums) {
    int ans = INT_MIN;
    for (int i = 0, j = nums.size() - 1; i < j; ) {
        int height = min(nums[i], nums[j]);
        ans = max(ans, height * (j - i));
        if (nums[i] < nums[j])  i++;
        else    j--;
    }
    return ans;
}