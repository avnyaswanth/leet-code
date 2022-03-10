class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end());
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
        }
        
        int res = 0;
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(s[i-1] == rs[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return n - dp[n][n];
    }
};