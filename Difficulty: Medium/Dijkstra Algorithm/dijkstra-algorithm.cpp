//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
  
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> dist(n,INT_MAX);
        vector<int> vis(n,0);
        
        set<pair<int,int>> st;
        st.insert({0,src});
        dist[src] = 0;
        //vis[src] = 1;
        
        while(!st.empty()){
            auto it = st.begin();
            int node = it->second;
            st.erase(it);
            vis[node] = 1;
            for(auto it : adj[node]){
                if(!vis[it.first]){
                    if((dist[node] + it.second) < dist[it.first]){
                        dist[it.first] = dist[node] + it.second;
                        st.insert({dist[it.first],it.first});
                    }
                }
            }
            //vis[node] = 1;
        }
        
        return dist;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends