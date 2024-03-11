class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int, int> mp;
        
        // Count the occurrences of each character in s
        for (int i = 0; i < s.size(); i++)
            mp[s[i] - 'a']++;
        
        string ans = "";
        
        // Iterate through the characters in order
        for (int i = 0; i < order.size(); i++) {
            // Append the character to ans as many times as its frequency
            while (mp[order[i] - 'a']) {
                ans.push_back(order[i]);
                mp[order[i] - 'a'] -= 1;
            }
        }
        
        // Append remaining characters from s to ans
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i] - 'a'])
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};