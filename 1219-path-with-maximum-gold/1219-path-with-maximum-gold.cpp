static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class Solution {
public:
    int vis[15][15];
    int rec (vector<vector<int>>&grid , int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==1)
        return 0;
        vis[i][j]=1;

        int ans =0;
        ans=max(ans,rec(grid , i,j+1));
        ans=max(ans,rec(grid , i,j-1));
        ans=max(ans,rec(grid , i-1,j));
        ans=max(ans,rec(grid , i+1,j));
        vis[i][j]=0;
        return ans+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        memset(vis,0,sizeof(vis));
        int ans=0;

        for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
        ans = max(ans,rec(grid,i,j));

        return ans;
        
    }
};