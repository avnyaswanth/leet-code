class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;++i)
            sum += arr[i];
        
        if(sum & 1) // if total sum is odd then we can't divide into two subsets
            return 0;
            
        sum /= 2;
            
        int dp[n+1][sum+1];
        
        for(int i=0;i<n+1;++i)
        {
            for(int j=0;j<sum+1;++j)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=sum;++j)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};