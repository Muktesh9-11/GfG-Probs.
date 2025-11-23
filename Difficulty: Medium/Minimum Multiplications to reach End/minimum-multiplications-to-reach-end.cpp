// User function Template for C++
static int MOD = 100000;
class Solution {
  public:
  int n;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        n = arr.size();
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int> dist(1e5,INT_MAX);
        dist[start] = 0;
        if(start == end) return 0;
        
        while(!q.empty()){
            auto[node,steps] = q.front();
            q.pop();
            
            for(auto it : arr){
                int num = (it*node) % MOD;
                if(steps+1 < dist[num]){
                    dist[num] = steps+1;
                    if(num == end) return steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        
        return -1;
        
        
    }
};
