/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int ans = 0;

    int totalNQueens(int n) {
        dfs(0, n, 0, 0, 0);
        return ans;
    }
    void dfs(int index, int n, int col, int pie, int na) {
        if (index >= n) {
            ans++;
            return;
        }
        // get all 空位
        int size = (~(col | pie | na)) & ((1 << n) - 1);
        while (size) {
            int bit = size & (-size);
            size -= bit;
            dfs(index + 1, n, col | bit, (pie | bit) << 1, (na | bit) >> 1);
        }
    }
};
// @lc code=end

