//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
   int solve(vector<int>& arr,int low,int high){
       if(arr[high]==0) return high+1;
       int mid=(low+high)/2;
       if(low>high) return mid;
       if(arr[mid]>=1) return solve(arr,low,mid-1);
       else return solve(arr,mid+1,high);
   }
  
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ans=m;
        int index=-1;
        for(int i=0;i<n;i++){
            if(ans!=m && arr[i][ans]==0) continue;
            else{
                int t=solve(arr[i],0,m-1);
                if(ans>t){
                ans=t;
                index=i;
                }
            }
        }
        return index;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends