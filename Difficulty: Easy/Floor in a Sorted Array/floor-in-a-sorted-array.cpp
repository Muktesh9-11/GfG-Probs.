//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    long long temp;
    int solve(vector<long long> &v, long long low,long long high, long long x){
        long long mid= (high+low)/2;
        
        if(low>high){
            if(x<v[high] && x>v[temp])return temp;
            else if(x>v[high])return high;
            else return -1;
        }
        temp=mid;
        if(v[mid]==x) return mid;
        else if(x<v[mid]){
            return solve(v,low,mid-1,x);
        }
        return solve(v,mid+1,high,x);
    }
    
    int findFloor(vector<long long> &v, long long n, long long x) {
        return solve(v,0,n-1,x);
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends