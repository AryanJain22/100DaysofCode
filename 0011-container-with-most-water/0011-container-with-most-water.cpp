class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx = INT_MIN;
        int start = 0;
        int end = height.size() - 1;
        int minn = 0;
        int k;
        while(start < end){
            minn = min(height[start], height[end]);
            k = end - start;
            int p = k * minn;
            maxx = max(maxx, p);
            if(height[start] <= height[end]){
                start += 1;
            }
            else{
                end -= 1;
            }
        }
        return maxx;
    }
};