class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int r,int c){
        int row = grid.size();
        int col = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vis[r][c] = 1;
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            auto node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();
           for (int k = 0; k < 4; k++) {

                int newx = x + dr[k];
                int newy = y + dc[k];

                if (newx >= 0 && newx < row &&
                    newy >= 0 && newy < col &&
                    grid[newx][newy] == '1' &&
                    !vis[newx][newy]) {

                    vis[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int island =0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(grid ,vis ,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};