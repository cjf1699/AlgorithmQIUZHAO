/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())   return false;
        unordered_map<char, int> mp;

        for (char c : s) {
            if (mp.find(c) == mp.end()) mp[c] = 0;
            mp[c]++;
        }

        for (char c : t) {
            if (mp.find(c) == mp.end()) return false;
            mp[c]--;
        }

        for (unordered_map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 0) return false;
        }

        return true;
    }
};
// @lc code=end

