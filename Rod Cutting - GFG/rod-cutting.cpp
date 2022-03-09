// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    
    int cutRod(int price[], int lens[], int n, int l)
    {
        if(n == 0)
            return 0;
        
        if(dp[n][l] != -1)
            return dp[n][l];
        if(lens[n-1] <= l)
           return dp[n][l] = max(price[n-1]+cutRod(price, lens, n, l-lens[n-1]), cutRod(price, lens, n-1, l));
        return dp[n][l] = cutRod(price, lens, n-1, l);
    }
    
    int cutRod(int price[], int n) {
        int lens[n];
        for(int i=0;i<n;++i)
            lens[i] = i+1;
            
        int l = n;
        return cutRod(price, lens, n, l);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends