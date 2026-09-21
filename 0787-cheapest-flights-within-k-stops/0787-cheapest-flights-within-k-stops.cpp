class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int weight = flights[i][2];
            adj[u].push_back({v,weight});
        }
        // stops , node , cost
        vector<int>dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto it:adj[node]){
                if(it.second + cost < dist[it.first] && stops <=k){
                    dist[it.first] = it.second + cost;
                    q.push({stops+1,{it.first,dist[it.first]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};