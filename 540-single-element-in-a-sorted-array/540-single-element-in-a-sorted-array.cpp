class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-2;
        while(l <= h)
        {
            int m = l + (h-l)/2;
            if(nums[m] == nums[m^1])
                l = m+1;
            else h = m-1;
        }
        return nums[l];
    }
};

/// open notes