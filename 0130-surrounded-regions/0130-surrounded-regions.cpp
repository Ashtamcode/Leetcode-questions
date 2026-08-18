class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                vis[i][0] = 1;
            }

            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                vis[i][n - 1] = 1;
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = 1;
            }

            if (board[m - 1][j] == 'O') {
                q.push({m - 1, j});
                vis[m - 1][j] = 1;
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dr[k];
                int ny = y + dc[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && board[nx][ny] == 'O'){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};