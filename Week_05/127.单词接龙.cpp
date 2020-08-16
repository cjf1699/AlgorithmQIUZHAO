/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            pair<string, int> cur = q.front();
            q.pop();
            string cur_s = cur.first;
            int len = cur.second;
            if (cur_s == endWord)   return len;
            for (int i = 0; i < cur_s.length(); i++) {
                for (char ch : "abcdefghijklmnopqrstuvwxyz") {
                    string new_str = cur_s.substr(0, i) + ch + cur_s.substr(i + 1, cur_s.length() - i - 1);
                    if (st.find(new_str) != st.end()) {
                        q.push({new_str, len + 1});
                        st.erase(st.find(new_str));
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

