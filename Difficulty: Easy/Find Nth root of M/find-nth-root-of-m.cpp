//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	long long int pwr(int m, int n){
	    long long int ans = 1;
	    for(int i = 0; i < n; i ++){
	        ans *= m;
	    }
	    if(ans <= 0 && m!=0)
	        return -1;
	    return ans;
	}
	int NthRoot(int n, int m)
	{long long int h=m,l=0;
	while(l<=h){
	  long long int mid=(l+h)/2;
	    if(pwr(mid,n)==m) return mid;
	    if (pwr(mid,n)>m || pwr(mid,n)<0) h=mid-1;
	    else l=mid+1;
	}
	
	 return -1;  
	   
	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends