class Solution {
public:
    void f(int i, vector<int> &nums, vector<int> &s, int k, int &count) {
        if (i >= nums.size()) {
            count++;
            return;
        }
        bool canInclude = true;
        for (int num : s) {
            if (abs(nums[i] - num) == k) {
                canInclude = false;
                break;
            }
        }
        if (canInclude) {
            s.push_back(nums[i]);

            f(i + 1, nums, s, k, count);

            s.pop_back();
        }

        f(i + 1, nums, s, k, count);
    }

    int beautifulSubsets(vector<int> &nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());
        vector<int> s;
        f(0, nums, s, k, count);
        return count - 1; 
    }
};
