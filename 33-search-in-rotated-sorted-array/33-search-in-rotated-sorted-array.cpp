class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n(nums.size());
        int l = 0, h = n-1;
        while(l <= h)
        {
            int m  = (l+h) >> 1;
            if(target == nums[m])
                return m;
            else if(nums[l] <= nums[m])
            {
                if(target < nums[m] && target >= nums[l])
                    h = m - 1;
                else l = m + 1;
            }
            else
            {
                if(target > nums[m] && target <= nums[h])
                    l = m + 1;
                else h = m - 1;
            }
        }
        return -1;
    }
};