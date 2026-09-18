class Solution {
private:
    bool dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis,int pr,int pc){
    
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr == pr && nc == pc)
                continue;
            if(nr < 0 || nr>=m || nc<0 || nc>=n ){
                continue;
            }
            if (grid[nr][nc] != grid[r][c])
                continue;
            if(vis[nr][nc]) return true;
            if(!vis[nr][nc] && grid[r][c] == grid[nr][nc]){

                if(dfs(nr,nc,grid,vis,r,c)) return true;
            }
        }
      
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int path = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,grid,vis,-1,-1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};