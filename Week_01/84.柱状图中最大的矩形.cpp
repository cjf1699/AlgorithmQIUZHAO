/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 1. 暴力解1， 超时
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int min_height = heights[i];
                for (int k = i + 1; k <= j; k++) {
                    min_height = min(min_height, heights[k]);
                }
                ans = max(ans, min_height * (j - i + 1));
            }
        }
        return ans;
        // 2. 暴力解2, 超时
        // 遍历每根柱子，寻找其左右边界
        int ans = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            // find left bound
            int left_bound = i, j;
            for (j = i - 1; j >= 0; j--) {
                if (heights[j] < heights[left_bound]) {
                    left_bound = j;
                    break;
                }
            }
            if (j < 0)  left_bound = j;

            // find right bound
            int right_bound = i;
            for (j = i + 1; j < n; j++) {
                if (heights[j] < heights[right_bound]) {
                    right_bound = j;
                    break;
                }
            }

            if (j >= n) right_bound = j;
            // cout << left_bound << ' ' << right_bound << endl;
            ans = max(ans, (right_bound - left_bound - 1) * heights[i]);
        }
        return ans;

        // 3. 栈
        // 当前柱子左边的其实已经遍历过，所以应该可以在O(1)内找
        // 到其左边界
        // 维护一个栈，栈内元素从小到大：单调栈
        // 这样，栈内某柱子的左边界就是它在栈内的下一个元素
        // 若当前柱子高度大于等于栈顶元素，说明栈顶元素的右边界还没找到，入栈
        // 若当前柱子高度小于栈顶元素，说明该柱子即为栈顶元素的右边界，出栈，
        // 处理， 当前元素入栈
        // O(n)循环结束，若栈非空，依次弹出处理

        stack<pair<int,int>> st;
        st.push({-1, -1});
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            if (heights[i] >= st.top().second) {
                st.push((i, heights[i]));
            }else {
                while (heights[i] < st.top()) {
                    int cur_top = st.top().second;
                    st.pop();
                    int left_bound = st.top().first;
                    ans = max(ans, (i - left_bound - 1) * cur_top);
                }
                st.push({i, heights[i]});
            }
        }
        while(st.top().first != -1) {
            int cur_top = st.top().second;
            st.pop();
            ans = max(ans, (n - st.top().first - 1) * cur_top);
        }
        return ans;
    }
};
// @lc code=end

