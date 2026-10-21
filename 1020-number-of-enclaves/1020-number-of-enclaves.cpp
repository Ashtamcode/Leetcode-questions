class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >=0 && nr<m && nc>=0 && nc<n &&  !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr,nc,grid,vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int land = 0;
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && grid[0][j] == 1) dfs(0, j, grid, vis);
            if (!vis[m-1][j] && grid[m-1][j] == 1) dfs(m-1, j, grid, vis);
        }
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0] == 1) dfs(i, 0, grid, vis);
            if (!vis[i][n-1] && grid[i][n-1] == 1) dfs(i, n-1, grid, vis);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    land++;
                }
            }
        }
        return land;


    }
};