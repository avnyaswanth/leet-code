class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = cost[0];
        dp[2] = cost[1];
        for(int i=3;i<=n;++i) {
            dp[i] = cost[i-1] + Math.min(dp[i-1], dp[i-2]);
        }
        return Math.min(dp[n], dp[n-1]);
    }
}