//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector<int>deg(n,0);
        vector<vector<int>>G(n);
        for(int i = 0; i < m; i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            G[v].push_back(u);
            deg[u]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(!deg[i]){
                q.push(i);
            }
        }
        vector<bool>visited(n,false);
        while(!q.empty()){
            int u = q.front(); q.pop();
            visited[u] = true;
            ans.push_back(u);
            for(auto v : G[u]){
                deg[v]--;
                if(!deg[v]){
                    q.push(v);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                return {};
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends