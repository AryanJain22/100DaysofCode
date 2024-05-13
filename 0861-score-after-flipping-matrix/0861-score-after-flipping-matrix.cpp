class Solution {
private:
    int binaryToDecimal(vector<int>& bits) {
        int n = bits.size();
        int ans = 0;
        int m = 1;
        while(n--) {
            ans += bits[n]*m;
            m *= 2;
        }
        return ans;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //flip rows
        for(int i = 0 ; i < n ; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0 ; j < m ; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        //flip cols
        for(int j = 1 ; j < m ; j++) {
            int zeros = 0;
            for(int i = 0 ; i < n ; i++) {
                if(grid[i][j] == 0) zeros++;
            }
            if(zeros > n/2) {
                for(int i = 0 ; i < n ; i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        int ans = 0;
        for(auto binary: grid) ans += binaryToDecimal(binary);
        return ans;
    }
};