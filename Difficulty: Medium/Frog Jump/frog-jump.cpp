#define ll long long
#define pb push_back

class Solution {
  public:
  
    ll solve(vector<int>& height, int i,vector<int>&dp){
        if(i == height.size()-1){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        ll cost1 = solve(height,i+1,dp)+abs(height[i]-height[i+1]);
        ll cost2 = INT_MAX;
        if(i + 2 < height.size())
            cost2 = solve(height,i+2,dp)+abs(height[i]-height[i+2]);
        
        return dp[i] = min(cost1,cost2);
        
    }
  
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size()+2,-1);
        //dp[0] = 0;
        return solve(height, 0,dp);
    }
};