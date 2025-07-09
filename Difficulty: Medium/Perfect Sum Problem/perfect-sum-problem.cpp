class Solution {
  public:
  int n;
  //int cnt = 0;
  
  const int MOD = 1e9 + 7;

    int solve1(vector<int>& arr, int target, int i, vector<vector<int>>& dp) {
        if (i == n) {
            return target == 0 ? 1 : 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int notTake = solve1(arr, target, i + 1, dp);
        int take = 0;
        if (arr[i] <= target)
            take = solve1(arr, target - arr[i], i + 1, dp);

        return dp[i][target] = (take + notTake) % MOD;
    }
  
    int solve(vector<int>arr,int target,int i,int cnt,vector<vector<int>>&dp){
        if(target == 0){
            return 1;
        }
        
        if(i== n-1) {
            if(arr[n-1] == target) return 1;
            return 0;
        }
        
        if(dp[i][target]!= -1) return dp[i][target];
        
        int left = solve(arr,target,i+1,cnt,dp);
        int right = 0;
        if(arr[i]<= target)
        right = solve(arr,target-arr[i],i+1,cnt,dp);
        
        return dp[i][target] = left+right;
        
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        n = arr.size();
        //sort(arr.begin(),arr.end());
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve1(arr,target,0,dp);
        
        //return cnt;
    }
};