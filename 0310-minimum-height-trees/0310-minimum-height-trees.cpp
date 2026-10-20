class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        if(n == 1)return {0};
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i] == 1){
                q.push(i);
            }
        }

        while(n>2){
            int size = q.size();
            n -= size;
            while(size--){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it] == 1){
                        q.push(it);
                        
                    }
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};