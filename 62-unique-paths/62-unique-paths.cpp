class Solution {
public:
    int dp[101][101];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    bool isSafe(int x, int y, int m, int n)
    {
        return x < m && y < n;
    }
    int findPath(int x, int y, int m, int n)
    {
        int ans = 0;
        if(x == m-1 && y == n-1)
            return 1;
        if(dp[x][y] != -1)
            return dp[x][y];
        if(isSafe(x+1, y, m, n))
            ans += findPath(x+1, y, m, n);
        if(isSafe(x, y+1, m, n))
            ans += findPath(x, y+1, m, n);
        dp[x][y] = ans;
        return dp[x][y];
    }
    
    int uniquePaths(int m, int n) {
        return findPath(0, 0, m, n);
    }
};