class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,long long& sum){
        int m = grid.size();
        int n = grid[0].size();
        sum +=grid[r][c];
        vis[r][c] = 1;
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = r+dr[k];
            int nc = c + dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc] !=0){
                dfs(nr,nc,grid,vis,sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long sum =0;
                    dfs(i,j,grid,vis,sum);
                    if(sum%k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};