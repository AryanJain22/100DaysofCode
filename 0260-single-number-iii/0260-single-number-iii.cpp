class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(!v.empty() && v.back() == nums[i]){
                v.pop_back();
            }
            else{
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};