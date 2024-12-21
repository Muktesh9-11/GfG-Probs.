//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool solve(vector<vector<int>> &adj, vector<int> & vis,int fix){
        vis[fix] = 1;
        queue<pair<int,int>>q;
        q.push({fix,-1});
        
        while(!q.empty()){
            int temp = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            //int sz = adj[temp].size();
            for(auto it : adj[temp]){
                if(!vis[it]){
                    q.push({it,temp});
                    vis[it]=1;
                }
                else if(it != parent) return true;
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int m = adj.size();
        vector<int> vis(m,0);
        
        for(int i=0;i<m;i++){
            if(!vis[i]){
                bool val = solve(adj,vis,i);
                if(val==true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends