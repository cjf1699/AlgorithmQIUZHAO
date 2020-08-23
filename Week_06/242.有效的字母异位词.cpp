/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_map(26, 0);
        vector<int> t_map(26, 0);
        for (char ch : s)   s_map[ch - 'a']++;
        for (char ch : t)   t_map[ch - 'a']++;
        for (int i = 0; i < 26; i++)    if (s_map[i] != t_map[i])   return false;
        return true;
    }
};
// @lc code=end

