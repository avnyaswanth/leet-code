class Solution {
public:
    void increaseleft(int &k, int l, vector<int> nums)
    {
        while(k < l && nums[k] == nums[k+1])
            k++;
    }
    void decreaseright(int k, int &l, vector<int> nums)
    {
        while(k < l && nums[l] == nums[l-1])
            l--;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n(nums.size());
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;++i)
        {
            for(int j=i+1;j<n-2;++j)
            {
                int a(nums[i]), b(nums[j]);
                int k = j+1, l = n-1;
                while(k < l)
                {
                   int c(nums[k]), d(nums[l]);
                    if(c + d < target-(a+b))
                    {
                        // increaseleft(k, l, nums);
                        k++;
                    }
                    else if(c + d > target-(a+b))
                    {
                        // decreaseright(k, l, nums);
                        l--;
                    }
                    else
                    {
                        ans.push_back(vector<int>({a, b, c, d}));
                        increaseleft(k, l, nums);
                        k++;
                        decreaseright(k, l, nums);
                        l--;
                    }
                }
                while(j+1<n-2 && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1<n-3 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};