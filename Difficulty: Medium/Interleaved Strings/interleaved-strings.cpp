class Solution {
  public:
  
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
        if(i == s1.size() && j == s2.size()){
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool bl1=false,bl2=false;
        
        if(s1[i] == s3[k] && i<s1.size()){
            bl1 = solve(s1,s2,s3,i+1,j,k+1,dp);
            //bool s2b = solve(s1,s2,s3,i,j,k+1);
            //bl1 = s1b || s2b; 
        }
        if(s2[j] == s3[k] && j<s2.size()){
            bl2 = solve(s1,s2,s3,i,j+1,k+1,dp);
            //bool s1b = solve(s1,s2,s3,i,j,k+1);
            //bl2 = s1b || s2b;
        }
        
        return dp[i][j] = (bl1 || bl2);
    }
  
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1, -1));
        return solve(s1,s2,s3,0,0,0,dp);
        
    }
};