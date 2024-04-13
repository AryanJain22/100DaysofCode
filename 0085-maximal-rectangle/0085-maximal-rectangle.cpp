class Solution {
public:
    int helper(vector<int> &histogram) {
        const int n = histogram.size();
        stack<int> stk;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && (i == histogram.size() || histogram[stk.top()] > histogram[i])) {
                int m = histogram[stk.top()];
                stk.pop();
                int v = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, m*v);
            }
            stk.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int ans = 0;
        if (matrix.empty()) return 0;

        vector<int> histogram(n, 0);
        for (auto &row : matrix) {
            for (int i = 0; i < n; i++) {
                histogram[i] = row[i] == '0' ? 0 : histogram[i]+1;
            }
            ans = max(ans, helper(histogram));
        }
        return ans;
    }
};