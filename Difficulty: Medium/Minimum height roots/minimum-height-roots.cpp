#define pb push_back
class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> count(V,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].pb(v);
            adj[v].pb(u);
            count[u]++;
            count[v]++;
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(count[i] == 1){
                q.push(i);
            }
        }
        
        int rem = V;
        while(rem>2){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();
                count[node]--;
                for(auto it : adj[node]){
                    count[it]--;
                    if(count[it] == 1){
                        q.push(it);
                    }
                }
            }
            rem -= sz;
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.pb(q.front());
            q.pop();
        }
        
        return ans;
    }
};