//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool solve(vector<int>& arr, int val){
        val = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]<= val) return false;
            val = arr[i];
        }
        return true;
    }
  
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        if(arr.size()<2) return true;
        return solve(arr,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends