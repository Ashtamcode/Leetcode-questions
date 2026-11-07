class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        //vector

        vector<double>prob(n,0.0);
        prob[start_node] = 1.0;
        // Node,dist

        priority_queue<pair<double, int>> pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int nei = it.first;
                double we = it.second;

                double curr_prob = dis*we;
                if(curr_prob > prob[nei]){
                    prob[nei] = curr_prob;
                    pq.push({curr_prob,nei});
                }
            }
        }
        return prob[end_node];
    }
};