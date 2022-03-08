class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n(nums.size());
        int res = 1;
        int lis[n];
        lis[0] = 1;
        for(int i=1;i<n;++i)
        {
            lis[i] = 1;
            for(int j=0;j<i;++j)
                if(nums[j] < nums[i] && lis[i] < lis[j]+1)
                    lis[i] = lis[j] + 1;
        }
        
        res = *max_element(lis, lis+n);
        
        return res;
    }
};