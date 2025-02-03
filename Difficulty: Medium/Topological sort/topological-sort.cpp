//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  vector<int> ans;
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int m = adj.size();
        //int n = adj[0].size();
        vector<int> indeg(m,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<m;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(int i=0;i<adj[t].size();i++){
                indeg[adj[t][i]]--;
                if(indeg[adj[t][i]] == 0) q.push(adj[t][i]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends