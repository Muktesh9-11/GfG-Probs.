//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
         int maxSum[n];//using to store maxsum till index i
        maxSum[0]=a[0];//assigning first element as default value
        
        //using kadanes algo to fill maxsum
        long long int currMax=a[0];
        for(int i=1;i<n;i++)
        {
           currMax=max(a[i],currMax + a[i]); 
           maxSum[i]=currMax;
        }
        
        //finding sum for the first k elements
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=a[i];
        }
        
        //using the sliding window
        int result=sum;
        for(int i=k;i<n;i++)
        {
            sum=sum+a[i]-a[i-k];
            result=max(result,sum);
            result=max(result,sum+maxSum[i-k]);
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends