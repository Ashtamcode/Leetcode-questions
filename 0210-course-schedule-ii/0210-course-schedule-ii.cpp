class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int>adj[V];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
                
            }
        }
        if(topo.size() !=V) return {};
        return topo;
    }
};