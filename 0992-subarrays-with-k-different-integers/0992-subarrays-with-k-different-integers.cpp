class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
private:
    int atMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0, result = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]]++ == 0) {
                ++count;
            }
            
            while (count > k) {
                if (--freq[nums[left]] == 0) {
                    --count;
                }
                ++left;
            }
            
            result += right - left + 1;
        }
        
        return result;
    }
};
