class Solution {
public:
    // int *dp[5001];
    // Solution()
    // {
    //     int **dp = new int*[5001];
    //     memset(dp, -1, sizeof(dp));
    // }
    // int changeUtil(vector<int> &coins, int amount, int n)
    // {
    //     if(amount == 0)
    //         return 1;
    //     if(n == 0)
    //        return 0;
    //     if(dp[n][amount] != -1)
    //         return dp[n][amount];
    //     if(coins[n-1] <= amount)
    //         return dp[n][amount] = changeUtil(coins, amount-coins[n-1], n) + changeUtil(coins, amount, n-1);
    //     return dp[n][amount] = changeUtil(coins, amount, n-1);
    // }
    
    int change(int amount, vector<int>& coins) {
        int n(coins.size());
        int dp[n+1][amount+1];
        // memset(dp, -1, sizeof(dp));
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=amount;++j)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][amount];
    }
};