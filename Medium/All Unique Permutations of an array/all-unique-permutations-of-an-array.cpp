//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void f(int ind, vector<int> &arr, set<vector<int>> &uniquePerms) {
        if (ind == arr.size()) {
            uniquePerms.insert(arr);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            swap(arr[ind], arr[i]);
            f(ind + 1, arr, uniquePerms);
            swap(arr[ind], arr[i]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> uniquePermsSet;
        f(0, arr, uniquePermsSet);
        vector<vector<int>> ans(uniquePermsSet.begin(), uniquePermsSet.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends