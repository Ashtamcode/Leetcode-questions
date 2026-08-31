class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int>adj[V];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int>indeg(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        int cnt =0;
        for(int i=0;i<V;i++){
            if(indeg[i] ==0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it] ==0)q.push(it);
            }
        }
        return cnt == V;
    }
};