class Solution {
public:
    void findSubsets(vector<int> nums, int i, int n, vector<vector<int>> &ans, 
                     vector<int> subset )
    {
        if(i == n)
        {
            ans.push_back(subset);
            return ;
        }
        findSubsets(nums, i+1, n, ans, subset);
        subset.push_back(nums[i]);
        findSubsets(nums, i+1, n, ans, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        findSubsets(nums, 0, n, ans, subset);
        set<vector<int>> st(ans.begin(), ans.end());
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};