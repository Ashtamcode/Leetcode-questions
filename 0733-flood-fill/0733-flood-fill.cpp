class Solution {
private:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,vector<vector<int>>&vis){
        int m = image.size();
        int n = image[0].size();
        
        int dr[] = {1,0,-1,0};
        int dc[]= {0,-1,0,1};
        vis[sr][sc] = 1;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){                                                                       // [[1,1,1],    
            int x = q.front().first;                                                            //   [1,1,0],
            int y = q.front().second;                                                              //[1,0,1]]
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dr[k];
                int ny = y + dc[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny] == image[sr][sc] && !vis[nx][ny]){
                    image[nx][ny] = color;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        image[sr][sc] = color;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        bfs(image,sr,sc,color,vis);
        return image;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(sr == i && sc)
        //     }
        // }
    }
};