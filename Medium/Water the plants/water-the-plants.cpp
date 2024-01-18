//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<int> plant(n,-1);
        for(int i = 0;i<n;i++){
            if(gallery[i] != -1){
                int a = max(0,i-gallery[i]);
                int b = min(n-1,i+gallery[i]);
                for(int j = a;j<=b;j++){
                    plant[j] = max(plant[j],b);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(plant[i] == -1){
                return -1;
            }
            if(i<=plant[i]){
                ans++;
                i = plant[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends