class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> mp;
        int ans;
        double p = arr.size() * 0.25;
        for(auto i: arr){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second > floor(p)){
                ans = i.first;
            }
        }
        return ans;
    }
};