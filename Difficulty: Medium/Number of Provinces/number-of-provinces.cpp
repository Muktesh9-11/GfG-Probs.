//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int ans=0;
    void solve(int node, vector<int>&visited,vector<vector<int>>&isConnected){
        visited[node]=1;
        for(int i=0;i<isConnected[node].size();i++){
                if(isConnected[node][i]==1 && !visited[i]){
                    solve(i,visited,isConnected);
                }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n=adj.size();
        vector<int> visited(n+1,0);
        //visited[0]=1;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                solve(i,visited,adj);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends