class Solution {
private:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.length() - 1;
        while (l <= r and s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }

    void help(const string &s, vector<vector<string>> &ans, vector<string> &current) {
        if (s.empty()) ans.emplace_back(current);
        for (int i = 1; i <= s.length(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (isPalindrome(left)) {
                current.emplace_back(left);
                help(right, ans, current);
                current.pop_back();
            }
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<string>> partition(const string &s) {
        vector<vector<string>> ans;
        vector<string> v;
        help(s, ans, v);
        return ans;
    }
};