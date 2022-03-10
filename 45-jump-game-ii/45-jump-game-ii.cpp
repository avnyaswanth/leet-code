class Solution {
public:
    int dp[10001];
    
    int jump(vector<int>& nums) {
        
        int n(nums.size());
        for(int i=0;i<10001;++i)
            dp[i] = 10001;
        
        dp[n-1] = 0;
        
        for(int i=n-2;i>=0;--i)
        {
            for(int j=1;j<=nums[i] && i+j < n;++j)
            {
                dp[i] = min(dp[i], 1 + dp[i+j]);
            }
        }
        
        return dp[0];
    }
};
