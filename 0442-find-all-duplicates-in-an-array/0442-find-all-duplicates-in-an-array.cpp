#include <unordered_map>

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> countMap;
        
        for (int num : nums) {
            countMap[num]++;
        }
        
        for (auto pair : countMap) {
            if (pair.second > 1) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};