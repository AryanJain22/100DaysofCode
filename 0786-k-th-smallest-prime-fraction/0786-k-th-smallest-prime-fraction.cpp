class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<tuple<double, int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                que.push({(double)arr[i]/arr[j], arr[i], arr[j]});
                if (k < que.size()) {
                    que.pop();
                }
            }
        }
        auto [_, i, j] = que.top();
        return vector<int>({i, j});
    }
};