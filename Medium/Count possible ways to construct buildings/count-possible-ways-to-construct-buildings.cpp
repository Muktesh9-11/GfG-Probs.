//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	long long fibonacci(int n) {
        const int mod_value = 1000000007;
        if (n <= 1) {
            return n;
        }
 
        long long t1 = 0, t2 = 1, nextTerm;
 
        for (int i = 2; i <= n; ++i) {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            nextTerm %= mod_value;
            t1 %= mod_value;
            t2 %= mod_value;
        }
 
        return t2;
    }
	
	
	int TotalWays(int N)
	{
	    const int mod_value = 1000000007;
    long long ans=fibonacci(N+2);
   return (ans*ans)%mod_value;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends