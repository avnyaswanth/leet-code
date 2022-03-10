class Solution {
public:
    int dp[10001];
    bool canJump(int idx, vector<int> &nums, int n)
    {
        if(idx >= n-1)
            return true;
        if(nums[idx] == 0)
            return false;
        if(dp[idx] != -1)
            return dp[idx];
        for(int i=idx+1;i<=idx+nums[idx];++i)
        {
            if(canJump(i, nums, n))
                return dp[i] = true;
        }
        return dp[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n(nums.size());
        return canJump(0, nums, n);
    }
};