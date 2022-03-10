// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int MCM(int arr[], int n, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int minMul = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = MCM(arr, n, i, k) + MCM(arr, n, k+1, j) + arr[i-1]*arr[k]*arr[j];
            minMul = min(temp, minMul);
        }
        
        return dp[i][j] = minMul;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        int n(N);
        return MCM(arr, n, 1, n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends