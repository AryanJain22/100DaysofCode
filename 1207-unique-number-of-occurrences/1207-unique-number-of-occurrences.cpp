class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        map<int, int> m;
        for(auto i: arr){
            mp[i]++;
        }
        for(auto c: mp){
            m[c.second]++;
        }
        for(auto i: m){
            if(i.second > 1){
                return false;
            }
        }
        return true;
    }
};