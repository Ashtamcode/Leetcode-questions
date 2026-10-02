class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int const MOD = 1e9 + 7;
         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int weight = roads[i][2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        vector<long long> dist(n, 1e18);
        vector<int>ways(n,0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dis > dist[node]) continue;
            for(auto it:adj[node]){
                long long edw = it.second;
                int no = it.first;
                if(edw+dis < dist[no]){
                    dist[no] = edw + dis;
                    ways[no] = ways[node];
                    pq.push({dist[no],no});
                }
                else if(edw + dis == dist[no]){
                    ways[no] = (ways[no] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};