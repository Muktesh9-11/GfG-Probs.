//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> weight(n,0);
        // int weight[n];
        vector<int> vis(n,0);
        
        queue<int> q;
        
        q.push(src);
        weight[src] = 0;
        while(!q.empty()){      // while(q.empty() != 1) 
            int node = q.front();
            q.pop();
            
            for(int i = 0;i<adj[node].size();i++){
                if(!vis[adj[node][i]]){
                    q.push(adj[node][i]);
                    vis[adj[node][i]] = 1;
                    weight[adj[node][i]] = weight[node]+1;
                }
            }
            //weight[node] = weight;
            //weight++;
        }
        
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++){
            if(weight[i] != 0){
                ans[i] = weight[i];
            }
        }
        ans[src] = 0;
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends