class Solution {
  public:
  
    bool solve(vector<vector<int>>&adj, int node, vector<int>&vis, 
                                                vector<int> &pathvis){
        
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(solve(adj,it,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[it]){
                return true;
            }
        }
        
        pathvis[node] = 0;
        return false;
        
    }
  
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>> adj(n);
        vector<int>vis(n,0), pathvis(n,0);
        
        for(auto it : prerequisites){
            int x = it[0];
            int y = it[1];
            adj[y].push_back(x);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            if(solve(adj,i,vis,pathvis)){
                return false;
            }
        }
        
        return true;
    }
};