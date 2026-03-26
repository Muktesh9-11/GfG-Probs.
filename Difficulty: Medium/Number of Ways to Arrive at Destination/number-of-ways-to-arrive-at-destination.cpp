#define pb push_back
class Solution {
  public:
  
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            
            adj[u].pb({v,cost});
            adj[v].pb({u,cost});
        }
        
        vector<int> dist(V,1e5+7);
        vector<int> ways(V,0);
        ways[0] = 1;
        dist[0] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [wt,u] = pq.top();
            pq.pop();
            
            if(wt > dist[u]) continue;
            
            for(auto it : adj[u]){
                int v = it.first;
                int time = it.second;
                if(wt + time < dist[v]){
                    dist[v] = wt+time;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if(wt+time == dist[v]){
                    ways[v] += ways[u];
                }
            }
        }
        
        return ways[V-1];
    }
};