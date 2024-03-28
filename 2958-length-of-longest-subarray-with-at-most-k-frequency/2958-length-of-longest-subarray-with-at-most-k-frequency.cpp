class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int first=0,j=0;
        int len=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>k){
                while(mp[nums[i]]>k){
                    mp[nums[first]]-=1;
                    first++;
                }
            }
            len=max(len,i-first+1);
        }
        return len;
    }
};