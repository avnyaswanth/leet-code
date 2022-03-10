class Solution {
public:
    int dp[10001];
    int jump(int idx, vector<int>& nums, int n)
    {
        if(idx >= n-1)
            return 0;

        if(dp[idx] != 10001)
            return dp[idx];
        
        for(int i=1;i<=nums[idx];++i)
            dp[idx] = min(dp[idx], 1 + jump(i+idx, nums, n));
        
        return dp[idx];
    }
    
    int jump(vector<int>& nums) {
        int n(nums.size());
        
        for(int i=0;i<10001;++i)
            dp[i] = 10001;
        
        int ans = jump(0, nums, n);
        return ans;
    }
};
