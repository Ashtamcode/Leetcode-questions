class Solution {
private:
    void dfs(int r,int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc  = c + dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] ==0){
                dfs(nr,nc,grid,vis);
            }
        }

    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(grid[i][0] == 0 && !vis[i][0]){
            dfs(i,0,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j] == 0 && !vis[0][j]){
            dfs(0,j,grid,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1] == 0 && !vis[i][m-1]){
            dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j] == 0 && !vis[n-1][j]){
            dfs(n-1,j,grid,vis);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};