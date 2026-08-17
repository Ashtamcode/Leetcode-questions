class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
                
            }
           
        }

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dis[x][y] = step;
            for(int k=0;k<4;k++){
                int nx = x + dr[k];
                int ny = y + dc[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny] =1;
                    q.push({{nx,ny},step+1});
                }
            }
        }
        return dis;
    }
};