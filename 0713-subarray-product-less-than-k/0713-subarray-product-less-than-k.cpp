class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int  i = 0 ;
        int  j = 0;
        int pro = 1;
        int count = 0 ;

        for(int i = 0 ; i < n ; i++){
            pro = pro* nums[i];
            while(j <= i && pro >= k){
                pro=pro/nums[j];
                j++;
            }
            count += i - j + 1;;
            
        }
        return count;
    }
};