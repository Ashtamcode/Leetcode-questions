class Solution {
private:
    bool dfs(int r,int c, vector<vector<int>>& vis,vector<vector<char>>& board,int pos,string word){
        if(pos == word.size()-1){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1;
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c+ dc[k];
            if(nr >= 0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc] == word[pos+1]){
                if (dfs(nr,nc,vis,board,pos+1,word)) {
                    return true;
                }
            }
        }
        vis[r][c] =0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == word[0]){
                    
                    if(dfs(i,j,vis,board,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};