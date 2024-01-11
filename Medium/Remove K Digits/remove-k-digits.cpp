//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
         if(k==S.size()) return "0";
        string str="";
        for(int i=0;i<S.size();i++){
            while(str.size()>0&&k>0&&str.back()>S[i]){
                str.pop_back();
                k--;
            }
            str+=S[i];
            
        }
        
        while(k>0&&str.size()>0){
            str.pop_back();
            k--;
        }
          int i=0;
         while(str[i]=='0' && i<str.size()){
           i++;
       }
      
        if(i==str.size()) return "0";
        return str.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends