class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v,weight});
        }

        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        dist[0][1] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;  //dist,node,count
        pq.push({0,{0,1}});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int count = pq.top().second.second;
            pq.pop();

            if (node == n - 1) return dis;
            for(auto it:adj[node]){
                int v = it.first;
                int w = it.second;

                int next_count = (labels[node] == labels[v]) ? count + 1 : 1;

                if(next_count <= k){
                    if (dis + w < dist[v][next_count]) {
                        dist[v][next_count] = dis + w;
                        pq.push({dist[v][next_count], {v, next_count}});
                    }
                }
                
            }
        }
        return -1;

    }
};