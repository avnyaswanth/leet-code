// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool ispalindrome(string str, int i, int j)
    {
        while(i < j)
        {
            if(str[i++] != str[j--])
                return false;
        }
        
        return true;
    }
    
    int mcm(string str, int i, int j)
    {
        if(i >= j)
            return 0;
           
        if(dp[i][j] != -1)
            return dp[i][j]; 
            
        if(ispalindrome(str, i, j))
            return 0;
            
        int res = INT_MAX;
        for(int k=i;k<j;++k)
        {
            int left , right;
            if(dp[i][k] != -1)
                left = dp[i][k];
            else
            {
                left = mcm(str, i, k);
                dp[i][k] = left;
            }
            
            if(dp[k+1][j] != -1)
                right = dp[k+1][j];
            else
            {
                right = mcm(str, k+1, j);
                dp[k+1][j] = right;
            }
            int ans = left + right + 1;
            res = min(ans, res);
        }
        
        return dp[i][j] = res;
    }
    
    int palindromicPartition(string str)
    {
        int n = str.length();
        memset(dp, -1, sizeof(dp));
        return mcm(str, 0, n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends