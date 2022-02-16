class Solution {
public:
    void permuteUtil(vector<int> nums,int l,int r,vector<vector<int>> &ans)
    {
        if(l==r)
        {
             ans.push_back(nums);
             return ;
        }
        for(int i=l;i<=r;++i)
        {
            swap(nums[i],nums[l]);
            permuteUtil(nums,l+1,r,ans);
            swap(nums[i],nums[l]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUtil(nums,0,nums.size()-1,ans);
        return ans;
    }
};