class Solution {
public:
    void combinationSumUtil(vector<int> &nums, vector<vector<int>> &ans, vector<int> combination,                              int i, int n, int target)
    {
        if(target == 0)
        {
            ans.push_back(combination);
            return ;
        }
        for(int j=i;j<n;++j)
        {
            if(nums[j] <= target)
            {
                if(j == i || nums[j] != nums[j-1])
                {
                    combination.push_back(nums[j]);
                    combinationSumUtil(nums, ans, combination, j+1, n, target-nums[j]);
                    combination.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        combinationSumUtil(nums, ans, combination, 0, nums.size(), target);
        return ans;
    }
};