class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int r,int c){
        vis[r][c] = 1;
        int m  =  board.size();
        int n = board[0].size();

        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr>=0 && nr < m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc] == 'X'){
                dfs(board,vis,nr,nc);
            }
        }
        
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int m  =  board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    dfs(board,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};