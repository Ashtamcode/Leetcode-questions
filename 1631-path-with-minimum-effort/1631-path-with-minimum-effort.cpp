class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == n-1 && c == m-1) return dis;
            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr<0 || nr>=n || nc<0 || nc>=m){
                    continue;
                }
                
                int neweff = max(abs(heights[nr][nc] - heights[r][c]),dis);
               
                if(neweff < dist[nr][nc]){
                    dist[nr][nc] = neweff;
                    pq.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return 0;
    }
};