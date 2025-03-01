//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj[V];
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(V,INT_MAX);
        
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(auto it : adj[temp]){
                if(dist[it[0]] > dist[temp] + it[1]){
                    dist[it[0]] = dist[temp] + it[1];
                    q.push(it[0]);
                }
            }
            
        }
        
        for(auto &it : dist){
            if(it == INT_MAX) it = -1;
        }
        
        return dist;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends