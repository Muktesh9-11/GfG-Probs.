class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            auto it = edges[i];
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // {weight, node}
        vector<int> vis(V,0);
        
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            // add to MST after this
            vis[node] = 1;
            sum+= wt;
            for(auto it : adj[node]){
                int adjnd = it.first;
                int edW = it.second;
                if(!vis[adjnd]){
                    pq.push({edW,adjnd});
                }
            }
        }
        
        return sum;
    }
};