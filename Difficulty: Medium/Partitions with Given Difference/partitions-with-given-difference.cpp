class Solution {
  public:
    int n;
    int total;
    int solve(vector<int>arr, int i,int sum,vector<vector<int>>&dp){
        if(i== n){
            if(sum == 0) return 1;
            return 0;
        }
        if(sum<0) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int notpick = solve(arr,i+1,sum,dp);
        int pick = 0;
        if(arr[i]<=sum) pick = solve(arr,i+1,sum-arr[i],dp);
        
        return dp[i][sum] = pick+notpick;
        
    }
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        // no need for absolute... (sum1>sum2)
        // no meet in middle algo
        
        n = arr.size();
        total = accumulate(arr.begin(),arr.end(),0);
        if((total - d)<0 || (total+d)%2 != 0) return 0;
        int sum = (total+d)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,0,sum,dp);
        
        
    }
};