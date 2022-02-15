class Solution {
public:
    void findSubsets(vector<int> nums, int i, int n, vector<vector<int>> &ans, 
                     vector<int> subset )
    {
        ans.push_back(subset);
        for(int j=i;j<n;++j)
        {
            if(j == i || nums[j] != nums[j-1])
            {
                subset.push_back(nums[j]);
                findSubsets(nums, j+1, n, ans, subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        findSubsets(nums, 0, n, ans, subset);
        return ans;
    }
};