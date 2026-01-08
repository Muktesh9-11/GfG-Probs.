// User function Template for C++
#define pb push_back

// disjoint set
class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        
        int findUltimateParent(int node){
            if(parent[node] == node){
                return node;
            }
            
            return parent[node] = findUltimateParent(parent[node]);
        }
        
        void UnionByRank(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void UnionBySize(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int, pair<int,int>>> adj;
       
            for(auto it : edges){
                int node = it[0];
                int adjnode = it[1];
                int wt = it[2];
                
                adj.pb({wt, {node,adjnode}});
            }
        
        DisjointSet ds(V);
        sort(adj.begin(),adj.end());
        int mstwt = 0;
        for(auto it : adj){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                mstwt += wt;
                ds.UnionBySize(u,v);
            }
        }
        
        return mstwt;
    }
};