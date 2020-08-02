/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<vector<int>> q;
        q.push(click);
        int m = board.size();
        int n = board[0].size();
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int x = cur[0], y = cur[1];
            if (board[x][y] == 'M') {
                board[x][y] = 'X';
                break;
            } else {
                int cnt = get_bomb(board, x, y, m, n);
                if (cnt > 0) {
                    board[x][y] = cnt + '0';
                    // break;
                } else {
                    board[x][y] = 'B';
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            int r = x + i, c = y + j;
                            if (r == x && c == y)   continue;
                            if (r < 0 || r >= m || c < 0 || c >= n) continue;
                            if (board[r][c] == 'E') {
                                q.push({r, c});
                                board[r][c] = 'B';
                            }
                        }
                    }
                }
            }
        }
        return board;
    }

    int get_bomb(vector<vector<char>>& board, int x, int y, int m, int n) {
        int cnt = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                int r = x + i, c = y + j;
                if (r == x && c == y)   continue;
                if (r < 0 || r >= m || c < 0 || c >= n) continue;
                if (board[r][c] == 'M') cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

