class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int weight = times[i][2];
            adj[u].push_back({v,weight});
        }
        vector<int>dis(n+1,1e9);
        dis[0] = -1;
        dis[k] = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({k,0});
        while(!pq.empty()){
            int node = pq.top().first;
            int d = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int nnode = it.first;
                int w = it.second;
                if(w+d < dis[nnode]){
                    dis[nnode] = w+d;
                    pq.push({nnode,dis[nnode]});
                }
            }
        }
        int m = *max_element(dis.begin(),dis.end());
        if(m == 1e9) return -1;
        else return m;
    }
};