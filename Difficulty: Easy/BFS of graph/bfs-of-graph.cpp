//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        visited[0]=1;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();i++){
                if(!visited[adj[temp][i]]){
                    q.push(adj[temp][i]);
                    visited[adj[temp][i]]=1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends