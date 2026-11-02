class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int sr=0,sc=0;
        //distance matrix will sum the dist so bakki inf hona chaiye

        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0] = grid[0][0];
        //dist,i,j

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{sr,sc}});


        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};

        while(!pq.empty()){
            int dist_n = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i == n-1 && j == n-1) return dist_n;
            for(int k=0;k<4;k++){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    if(max(dist_n, grid[nr][nc])< dis[nr][nc]){
                        dis[nr][nc] = max(dist_n, grid[nr][nc]);
                        pq.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
        
    }
};