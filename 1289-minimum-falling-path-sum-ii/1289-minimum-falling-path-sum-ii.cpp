class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col,999999));

        for(int i= 0; i<col; i++)dp[row-1][i] = grid[row-1][i];

        for(int i= row-2; i>=0; i--){
            for(int j=0; j<col; j++) {
                for(int k=0; k<col; k++) {
                    if(k==j)continue;

                    dp[i][j] = min(dp[i][j], dp[i+1][k]+grid[i][j]);
                }
            }
        }
        
        int ans=999999;
        for(int i=0;i<col;i++){
            ans = min(dp[0][i], ans);
        }

        return ans;
    }
};
