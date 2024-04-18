class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    //    trying brute force;
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                
                if(grid[i][j]==1){
                    int k=4;
                    if(i!=0){
                        if(grid[i-1][j]==1){
                            k--;
                        }
                    }
                    if(i!=grid.size()-1){
                        if(grid[i+1][j]==1){
                            k--;
                        }
                    }
                    if(j!=0){
                        if(grid[i][j-1]==1){
                            k--;
                        }
                    }
                    if(j!=grid[0].size()-1){
                        if(grid[i][j+1]==1){
                            k--;
                        }
                    }
                    ans+=k;

                }
            }
        }
        return ans;
    }
};