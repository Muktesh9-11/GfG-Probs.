#define ll long long
class Solution {
  public:
  
    int solve(vector<int>&arr, int i, int prev, vector<vector<int>>&dp){
        if(i == arr.size()){
            return 0;
        }
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        ll notpick = solve(arr,i+1,prev,dp);
        ll pick = 0;
        if(arr[prev] < arr[i] || prev==-1){
            pick = arr[i] + solve(arr,i+1,i,dp);
        }
        
        return dp[i][prev+1] = max(pick,notpick);
    }
  
    int maxSumIS(vector<int>& arr) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        int prev = -1;
        return solve(arr,0,-1,dp);
    }
};